#pragma once

class Creature
{
public:
	Creature() {};
	virtual bool playerGoTo(int x, int y);
	virtual void fight();
	virtual void takeDamage();
protected:
	Creature(char sign, int hp, int attack, int defence);
private:
	char sign;
	int hp;
	int attack;
	int defence;
};