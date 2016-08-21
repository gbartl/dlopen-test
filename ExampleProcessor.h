#pragma once

#include "Processor.h"

class ExampleProcessor : public Processor {
 public:
    ExampleProcessor() = default;
    virtual ~ExampleProcessor() = default;
    bool process(uint8_t * data, const uint32_t length); 
};


