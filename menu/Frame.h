#pragma once
#include <string>
class Frame
{
public:
	Frame(int width, int height);
	void printFrame();
	virtual void printInside();
	bool isInside(int x, int y);
	void print(int x, int y);
private:
	void printVertical(int x,int y,int width);
	void printHorizontal(int x, int y, int height);
	
	
	char wall = '|';
	//char top_right = '\u2557';
	//char top_left = '\u2554';
	//char bottom_right = '\u2255D';
	//char bottom_left = '\u255A';
	char dash = '_';
protected:
	void printPoint(int x, int y, char sign);
	void printLine(int line, std::string text);
	void printCenterLine(int line, std::string text);
	int width;
	int height;
	int x;
	int y;
	
};

