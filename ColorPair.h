#ifndef COLORPAIR_H
#define COLORPAIR_H

typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

void initializeColorPairs();
ColorPair getColorFromPairNumber(int pairNumber);
int getPairNumberFromColor(ColorPair pair);
void logMessage(const char* message);

#endif // COLORPAIR_H
