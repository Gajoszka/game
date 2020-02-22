#include "InfoDisplay.h"
#include"Frame.h"
#include <iostream>

using namespace std;

InfoDisplay::InfoDisplay() : Frame(45, 5) {

}

void InfoDisplay::printInside() {
	printLine(1, "Dzieñ dobry");
}