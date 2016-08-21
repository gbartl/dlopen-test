#pragma once

#include "Processor.h"

#include <vector>

using std::vector;

class ProcessorLoader {
 public:
    ProcessorLoader();
    ~ProcessorLoader();
    bool openLib(const char * sharedLibPath);
    vector<Processor*> createProcessingChainInstance();
 private:
    vector<Processor*> allProcessors;
    vector<void*> sharedLibs;
};
