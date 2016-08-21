#include "ExampleProcessor.h"
#include <iostream>

extern "C" ProcessingModule * create() {
    return new ExampleProcessor; 
}

extern "C" void destroy(ProcessingModule * module) {
    delete module;
}

bool ExampleProcessor::process(int value) {
    aValue = value;
    doStuff();
    return true;
}

void ExampleProcessor::doStuff() {
    std::cout<<aValue<<std::endl;
}

