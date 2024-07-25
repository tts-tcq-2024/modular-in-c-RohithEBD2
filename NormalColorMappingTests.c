#include "NormalColorMappingTests.h"
#include "ColorPair.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void validateColorMapping(int pairNumber, const char* expectedMajor, const char* expectedMinor) {
    ColorPair colorPair = getColorFromPairNumber(pairNumber);
    printf("[In]Pair Number: %d, [Out] Colors: MajorColor:%s, MinorColor:%s\n", pairNumber, colorPair.majorColor, colorPair.minorColor);
    assert(strcmp(colorPair.majorColor, expectedMajor) == 0);
    assert(strcmp(colorPair.minorColor, expectedMinor) == 0);
}

void validatePairNumberMapping(const char* majorColor, const char* minorColor, int expectedPairNumber) {
    ColorPair colorPair = {majorColor, minorColor};
    int pairNumber = getPairNumberFromColor(colorPair);
    printf("[In]Colors: MajorColor:%s, MinorColor:%s, [Out] PairNumber: %d\n", colorPair.majorColor, colorPair.minorColor, pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void runNormalColorMappingTests() {
    validateColorMapping(4, "White", "Brown");
    validateColorMapping(5, "White", "SlateGray");
    validateColorMapping(23, "Violet", "Green");
    validatePairNumberMapping("Yellow", "Green", 18);
    validatePairNumberMapping("Red", "Blue", 6);
}
