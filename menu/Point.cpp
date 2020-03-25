#include "Point.h"
/* Tracking one's coordinates*/
using namespace std;

Point::Point(int column, int row) {
	setColumn(column);
	setRow(row);
}
void Point::setColumn(int value) {
	this->column = value;
}
void Point::setRow(int value) {
	this->row = value;
}

int Point::getColumn() {
	return column;
}

int Point::getRow() {
	return row;
}