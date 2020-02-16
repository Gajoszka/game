#pragma once
class Frame
{
public:
	Frame(int width, int height);
	void printFrame(int x, int y);
private:
	void printVertical(int x,int y,int width);
	void printHorizontal(int x, int y, int height);
	int width;
	int height;
};

