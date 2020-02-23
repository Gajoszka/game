#pragma once

class Creature
{
public:
	Creature(int hp, int attack, int defence);
	virtual bool playerGoTo(int x, int y);
	virtual void attack();
	virtual void takeDamage();
private:
	int hp;
	int attack;
	int defence;
};