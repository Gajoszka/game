#include "InfoDisplay.h"
#include"Frame.h"
#include <iostream>

using namespace std;

void InfoDisplay::printInside() {
	for (int i=0;i<content.size();i++)
		printCenterLine(i+1, content[i]);
}