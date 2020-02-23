#pragma once
class Point
{
public:
	Point(int x, int y) {
		setX( x);
		setY(y);
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y= y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
private: int x=0, y=0;
};

