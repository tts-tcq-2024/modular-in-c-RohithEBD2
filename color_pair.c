#include "ColorPair.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "SlateGray"};
int numMajorColors = 5;
int numMinorColors = 5;

void initializeColorPairs() {
    // Initialization is done through static arrays, nothing needed here
}

ColorPair getColorFromPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > numMajorColors * numMinorColors) {
        fprintf(stderr, "Argument PairNumber:%d is outside the allowed range\n", pairNumber);
        exit(EXIT_FAILURE);
    }
    
    int zeroBasedPairNumber = pairNumber - 1;
    int majorIndex = zeroBasedPairNumber / numMinorColors;
    int minorIndex = zeroBasedPairNumber % numMinorColors;

    ColorPair pair = {majorColors[majorIndex], minorColors[minorIndex]};
    return pair;
}

int getPairNumberFromColor(ColorPair pair) {
    int majorIndex = -1;
    int minorIndex = -1;

    for (int i = 0; i < numMajorColors; i++) {
        if (strcmp(majorColors[i], pair.majorColor) == 0) {
            majorIndex = i;
            break;
        }
    }
    
    for (int i = 0; i < numMinorColors; i++) {
        if (strcmp(minorColors[i], pair.minorColor) == 0) {
            minorIndex = i;
            break;
        }
    }
    
    if (majorIndex == -1 || minorIndex == -1) {
        fprintf(stderr, "Unknown Colors: Major: %s, Minor: %s\n", pair.majorColor, pair.minorColor);
        exit(EXIT_FAILURE);
    }

    return (majorIndex * numMinorColors) + (minorIndex + 1);
}

void logMessage(const char* message) {
    printf("%s\n", message);
}
