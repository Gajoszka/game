#pragma once
/* Creating the opening menu*/
#include "KeyFunctions.h"
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
	KeyFunctions obj;
	void intro();
	void play(string name);
};
