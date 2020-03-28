#include "InfoFrame.h"
#include"Frame.h"
#include <iostream>
#include <string>
/*Frame for displaying current information to the player*/
using namespace std;

// printing inside information frames
void InfoFrame::printInside() {
	for (int i=0;i<content.size();i++)
		printLine(i+1, content[i]);
}

void InfoFrame::addContent(int rowNr, string content) {
	if (rowNr > 0 && rowNr < content.size()) {
		this->content[rowNr - 1] = content;
		Frame::printLine(rowNr, content);
	}
}