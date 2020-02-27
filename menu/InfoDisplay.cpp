#include "InfoDisplay.h"
#include"Frame.h"
#include <iostream>
#include <string>
using namespace std;

// printing inside information frames
void InfoDisplay::printInside() {
	for (int i=0;i<content.size();i++)
		printCenterLine(i+1, content[i]);
}

//
void InfoDisplay::printLine(int rowNr, string content) {
	if (rowNr > 0 && rowNr < content.size()) {
		this->content[rowNr - 1] = content;
		printInside();
	}
}