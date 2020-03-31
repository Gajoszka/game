#pragma once
/* Creating the opening menu*/
#include "DBconnection.h"
#include "Frame.h"
#include <vector>
#include <string>
#include "MenuTemplate.h"
using namespace std;

class MainMenu
{
public:
	void showMenu();
protected:

private:
	DBconnection db;
	MenuTemplate menu;
	int answer;
	bool active = true;
	void intro();
	void play(string name);
	void key_fun();
	void getOptions();
	vector<string> menu_options;
	string new_game = "Start new game";
	string keys = "Key functions";
	string scores = "Score board";
	string exit = "Exit";
};
