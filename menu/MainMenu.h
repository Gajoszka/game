#pragma once
/* Creating the opening menu*/
#include "DBconnection.h"
#include "Frame.h"
#include <string>
using namespace std;

class MainMenu : public Frame
{
public:
	MainMenu();
	void user_choice();
	virtual void printInside();

protected:

private:
	DBconnection db;
	void intro();
	void play(string name);
};
