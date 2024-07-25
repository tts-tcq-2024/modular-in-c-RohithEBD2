#include "AbnormalValueTests.h"
#include "ColorPair.h"
#include <stdio.h>
#include <stdlib.h>

void validateAbnormalPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > 25) {
        fprintf(stderr, "Argument PairNumber:%d is outside the allowed range\n", pairNumber);
    } else {
        getColorFromPairNumber(pairNumber);
    }
}

void validateAbnormalColors(ColorPair pair) {
    const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "SlateGray"};
    int majorIndex = -1;
    int minorIndex = -1;

    for (int i = 0; i < 5; i++) {
        if (strcmp(majorColors[i], pair.majorColor) == 0) {
            majorIndex = i;
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (strcmp(minorColors[i], pair.minorColor) == 0) {
            minorIndex = i;
            break;
        }
    }

    if (majorIndex == -1 || minorIndex == -1) {
        fprintf(stderr, "Unknown Colors: Major: %s, Minor: %s\n", pair.majorColor, pair.minorColor);
    } else {
        getPairNumberFromColor(pair);
    }
}

void runAbnormalValueTests() {
    validateAbnormalPairNumber(0);
    validateAbnormalPairNumber(26);
    ColorPair testPair = {"Pink", "Blue"};
    validateAbnormalColors(testPair);
}
