#include <string>
#include "ProcessingModule.h"

using std::string;

class ExampleProcessor : public ProcessingModule {
 public:
    ExampleProcessor() = default;
    virtual ~ExampleProcessor() = default;
    bool process(int value);
 private:
    void doStuff();
    int aValue;
};


