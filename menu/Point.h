#pragma once
class Point
{
public:
	Point(int column,int row) {
		setColumn( column);
		setRow(row);
	}
	void setColumn(int value) {
		this->column = value;
	}
	void setRow(int value) {
		this->row= value;
	}

	int getColumn() {
		return column;
	}

	int getRow() {
		return row;
	}
private: int column=0, row=0;
};

