#pragma once
#include "Frame.h"

class InfoDisplay : public Frame
{
public:
	InfoDisplay();
	virtual void printInside();
	void printTemporaryContent(std::string content) {
		printCenterLine(1, content);
	}
	void setContent(int nr, std::string content) {
		if (nr > 0 && nr <= 4) {
		this->content[nr-1] = content;
		printInside();
	}
	}

private:
	std::string content[4] = { "","","" ,""};
};

