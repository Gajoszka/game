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
	int getScore() {
		return score;
	}
private:
	int score=0;
};

