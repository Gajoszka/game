#pragma once
/*Class for all frames that are used to display information*/
#include "Frame.h"
#include <vector>
#include <string>
using namespace std;

class InfoFrame : public Frame
{
public:
	InfoFrame(int width, int height) : Frame(width, height) {
		for (int i = 0; i < height - 1; i++)
			content.push_back("");
	}
	virtual void printInside();
	void printLine(int rowNr, std::string content);

private:
	vector<string> content;
};

