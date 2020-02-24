#pragma once
#include "Frame.h"


class Stats : public Frame
{
public:
	Stats();
	virtual void printInside();
	void addScore(int s) {
		score = score + s;
		printInside();
	}
private:
	int score=0;
};

