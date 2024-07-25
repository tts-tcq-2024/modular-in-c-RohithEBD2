#include "color_pair.h"
#include <stdio.h>

void validateAbnormalPairNumber(int pairNumber) {
    try {
        getColorFromPairNumber(pairNumber);
    } catch (const std::out_of_range &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void validateAbnormalColors(ColorPair pair) {
    try {
        getPairNumberFromColor(pair);
    } catch (const std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void runAbnormalValueTests() {
    validateAbnormalPairNumber(0);
    validateAbnormalPairNumber(26);
    validateAbnormalColors({"Pink", "Blue"});
}
