#include "ProcessorLoader.h"

#include <string>
#include <vector>

#include <dlfcn.h>

#include "Processor.h"

using std::vector;

ProcessorLoader::ProcessorLoader() : allProcessors(), sharedLibs() {   
}

ProcessorLoader::~ProcessorLoader() {
    for(auto & processor : allProcessors) {
        destroy(processor);
    }

    for(auto & lib : sharedLibs) {
       dlclose(lib);
    }
}

bool ProcessorLoader::openLib(const char * sharedLibPath) {
    bool success = false;

    void * lib = dlopen(sharedLibPath, RTLD_NOW);
    if (lib) {
        sharedLibs.push_back(lib);
        success = true;
    }

    return success;
}

vector<Processor*> ProcessorLoader::createProcessingChainInstance() {
    vector<Processor*> chainInstanceProcessors;
    for (auto & lib : sharedLibs) {
        create_t * createProcessor = (create_t*) dlsym(lib, "create"); 
        const char * dlsym_error = dlerror();
        if (dlsym_error == nullptr) {
            Processor * processor = createProcessor();
            if (processor) {
                allProcessors.push_back(processor);
                chainInstanceProcessors.push_back(processor);
            }
        }
    }
    return chainInstanceProcessors;    
}