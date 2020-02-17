#include "Stats.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>

using namespace std;

void Stats::frame() {
    Frame stats(width, height);
    stats.printFrame(x, y);
}