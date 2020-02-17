#include "InfoDisplay.h"
#include"Frame.h"
#include <iostream>

using namespace std;

void InfoDisplay::infoFrame() {
	Frame info(width, height);
	info.printFrame(x,y);
};