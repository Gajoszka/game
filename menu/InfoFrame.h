#pragma once
/*Frames for displaying current information to the player*/
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
	void addContent(int rowNr, std::string content);

private:
	vector<string> content;
};