#pragma once

#include "Processor.h"

class AnotherProcessor : public Processor {
 public:
    AnotherProcessor() = default;
    virtual ~AnotherProcessor() = default;
    bool process(uint8_t * data, uint32_t length);
};


