#include "Stats.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>

using namespace std;

StatsFrame::StatsFrame() : Frame(20, 24) {

}

void StatsFrame::printInside() {
	for (int i = 0; i < 12; i++)
		printLine(i + 1, content[i]);
}