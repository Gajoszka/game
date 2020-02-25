#pragma once
#include "Point.h"
class Creature
{
public:
	Creature();
	virtual void print(int x, int y);
	void clear();
	virtual void fight();
	virtual void takeDamage();
	Point getLocation() {
		return location;
	};

	void setLocation(Point l) {
		location = l;
	};

	void setLocation(int x, int y) {
		location.setColumn(x);
		location.setRow(y);
	};
protected:
	Creature(char sign, int hp, int attack, int defence);
private:
	char icon;
	int hp;
	int attack;
	int defence;
	Point location;
};

