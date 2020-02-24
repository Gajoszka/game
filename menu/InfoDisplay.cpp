#include "InfoDisplay.h"
#include"Frame.h"
#include <iostream>

using namespace std;

InfoDisplay::InfoDisplay() : Frame(48, 5) {

}

void InfoDisplay::printInside() {
	for (int i=0;i<4;i++)
		printCenterLine(i+1, content[i]);
}