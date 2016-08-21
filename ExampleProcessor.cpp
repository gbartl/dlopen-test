#include "ExampleProcessor.h"
#include "Processor.h"

extern "C" Processor * create() {
    return new ExampleProcessor; 
}

bool ExampleProcessor::process(uint8_t * data, uint32_t length) {
	for (int i=0; i< length; ++i) {
		++data[i];
	}
    return true;
};