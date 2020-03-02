#pragma once
/* Creating the opening menu*/
#include "DBconnection.h"
#include "Frame.h"
#include <vector>
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
	int answer;
	void intro();
	void play(string name);
	void key_fun();
	int chooseIndex(string head, vector<string> options, string prompt);
	string chooseOption(string head, vector<string> options, string prompt);
	int menuDisplay(string head, vector<string>options);
	void nameDisplay(string name);
	void showMenuLine(int index, string text);
	int getValidInput(string prompt, int highestNum);
	void showMenu();
	vector<string> menu_options;
	string new_game = "Start new game";
	string keys = "Key functions";
	string scores = "Score board";
	string exit = "Exit";
};
