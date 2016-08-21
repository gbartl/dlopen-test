#include <iostream>
#include <vector>
#include <thread>

#include <dlfcn.h>

#include "Processor.h"
#include "ProcessorLoader.h"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char * argv[]) {
    int retVal = 1;

    ProcessorLoader processorLoader;

    bool libsOK = true;
    for (int i=1; i<argc; ++i) {
        bool libOpenSuccess = processorLoader.openLib(argv[i]);
        if (libOpenSuccess == false) {
            libsOK = false;
        }
    }

    if (libsOK == true) {        
        vector<Processor*> processors = processorLoader.createProcessingChainInstance();
        
        uint8_t data[]= {0,1,2,3,4};
        for (int i=0; i<sizeof(data); ++i) {
            cout<<(int)data[i]<<" ";
        }
        cout<<endl;
        for(auto processor : processors) {
            processor->process(data, sizeof(data));
        }

        for (int i=0; i<sizeof(data); ++i) {
            cout<<(int)data[i]<<" ";
        }
        cout<<endl;     
    }

    return 0;
};