#pragma once
#include "InfoFrame.h"
#include <vector>
#include <string>
using namespace std;

class Shop
{
public:
	Shop() : shopFrame(30, 15) {};
	void openShop();

private:
	void shopMenu();
	void buyWeapon();
	void buyAmmunition();
	void leaveShop();
	InfoFrame shopFrame;
	vector<string> content;
};

