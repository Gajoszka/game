#pragma once
class Point
{
public:
	Point(int column, int row);
	void setColumn(int value);
	void setRow(int value);
	int getColumn();
	int getRow();
private:
	int column=0, row=0;
};

