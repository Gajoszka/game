#include "InfoFrame.h"
#include"Frame.h"
#include <iostream>
#include <string>
/*Frame for displaying current information to the player*/
using namespace std;

// printing inside information frames
void InfoFrame::printInside() {
	for (int i=0;i<content.size();i++)
		printCenterLine(i+1, content[i]);
}

void InfoFrame::printLine(int rowNr, string content) {
	if (rowNr > 0 && rowNr < content.size()) {
		Frame::printLine(rowNr, content);
	}
}