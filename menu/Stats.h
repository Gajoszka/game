#pragma once
#include "Frame.h"


class Stats : public Frame
{
public:
	Stats();
	virtual void printInside();
	void printScore(int score) {
		content[1]= "Score: " + std::to_string(score);
		printLine(1, content[1]);
	}
	
private:
	std::string content[12] = { "","","" ,"","","","","","","","","" };
};

