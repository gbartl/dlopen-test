#include <iostream>
#include <dlfcn.h>
#include "ProcessingModule.h"

using namespace std;

int main(int argc, char * argv[]) {
    void * lib = dlopen(argv[1], RTLD_LAZY);
    if (lib == nullptr) {
        cout<<"error opening: "<<argv[1]<<endl;
        return 1;
    } else {
        cout<<"successfully opened: "<<argv[1]<<endl;
    }

    dlerror();

    const char * dlsym_error;

    create_t* createProcessor = (create_t*) dlsym(lib, "create");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cout << "Cannot load symbol create: " << dlsym_error << endl;
        return 1;
    } else {
        cout << "got creator" << endl;
    }

    destroy_t* destroyProcessor = (destroy_t*) dlsym(lib, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cout << "Cannot load symbol destory: " << dlsym_error << endl;
        return 1;
    } else {
        cout << "got destroyer" << endl;
    }

    ProcessingModule * aProcessor = createProcessor();
    bool retVal = aProcessor->process(12);
    if (retVal == true) {
        cout<<"great success"<<endl;
    }
}