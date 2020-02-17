#pragma once
#include <string>
class Frame
{
public:
	Frame(int width, int height);
	void printFrame(int x, int y);
	bool isInside(int x, int y);
private:
	void printVertical(int x,int y,int width);
	void printHorizontal(int x, int y, int height);
	void printPoint(int x, int y, char sign);
	int width;
	int height;
	int x;
	int y;
	//char wall = '\u2551'; 
	//char top_right = '\u2557';
	//char top_left = '\u2554';
	//char bottom_right = '\u2255D';
	//char bottom_left = '\u255A';
	//char dash = '\u2550';
};

