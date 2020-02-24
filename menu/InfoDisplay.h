#pragma once
#include "Frame.h"

class InfoDisplay : public Frame
{
public:
	InfoDisplay();
	virtual void printInside();
	void setTemporaryContent(std::string content) {
		printCenterLine(1, content);
	}
	void setContent(std::string content) {
		this->content = content;
		printInside();
	}

private:
	std::string content;
};

