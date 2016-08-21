#include <iostream>
#include <vector>

#include <dlfcn.h>

#include "Processor.h"
#include "ProcessorLoader.h"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char * argv[]) {
    int retVal = 1;
    ProcessorLoader processorLoader;

    bool processorsOK = true;
    for (int i=1; i<argc; ++i) {
        bool processorLoaded = processorLoader.openLib(argv[i]);
        if (processorLoaded == false) {
            processorsOK = false;
        }
    }

    if (processorsOK == true) {
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
        retVal = 0;
    }

    return retVal;
};