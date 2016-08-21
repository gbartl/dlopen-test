#include "AnotherProcessor.h"
#include "Processor.h"

extern "C" Processor * create() {
    return new AnotherProcessor; 
}

bool AnotherProcessor::process(uint8_t * data, const uint32_t length) {
	for (int i=0; i< length; ++i) {
		data[i] = data[i] * 2;
	}
    return true;
}