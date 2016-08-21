#pragma once

#include <stdint.h>

class Processor {
 public:
 	Processor() = default;
 	virtual ~Processor() = default;
	virtual bool process(uint8_t * data, uint32_t length) = 0;
};

typedef Processor* create_t();
typedef void destroy_t(Processor*);

extern "C" inline void destroy(Processor * module) {
    delete module;
}
