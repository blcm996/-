// main.cpp
#include "BoolInvariantGenerator.h"
#include <iostream>

int main() {
    BoolInvariantGenerator boolGen;
    boolGen.generate();
    std::cout << "Invariant generation completed." << std::endl;
    return 0;
}