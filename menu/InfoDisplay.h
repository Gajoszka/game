#pragma once
#include "Frame.h"
#include <vector>
using namespace std;

class InfoDisplay : public Frame
{
public:
	InfoDisplay(int width, int height) : Frame(width, height) {
		for (int i = 0; i < height - 1; i++)
			content.push_back("");
	}
	virtual void printInside();

	void printLine(int rowNr, std::string content) {
		if (rowNr > 0 && rowNr < content.size()) {
			this->content[rowNr - 1] = content;
			printInside();
		}
	}


private:
	vector<std::string> content;
};

