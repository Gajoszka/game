#pragma once
#include "Frame.h"


class StatsFrame : public Frame
{
public:
	StatsFrame();
	virtual void printInside();
	void printScore(int score) {
		content[1]= "Score: " + std::to_string(score);
		printLine(2, content[1]);
	}
	void printName(std::string name) {
		content[0] = "Player: " + name;
		printCenterLine(1, content[0]);
	}
private:
	std::string content[12] = { "","","" ,"","","","","","","","","" };
};

