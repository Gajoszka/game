#ifndef MAINMENU_H
#define MAINMENU_H
#include "Frame.h"


class MainMenu : public Frame
{
public:
	MainMenu();
	void user_choice();
//	virtual void print(int x,int y);
	//virtual void printFrame();
	virtual void printInside();

protected:

private:
	void intro();
	void play();
};

#endif // MAINMENU_H