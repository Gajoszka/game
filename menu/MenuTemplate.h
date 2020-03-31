#pragma once
#include <vector>
#include <string>
#include "Frame.h"
using namespace std;

class MenuTemplate : public Frame
{
public:
	MenuTemplate() : Frame(0, 0) {};
	string chooseOption(string head, vector<string> options, string prompt);
	void showOptions(vector<string> list);
private:
	int chooseIndex(string head, vector<string> options, string prompt);
	void nameDisplay(string name);
	void showMenuLine(int index, string text);
	int getValidInput(string prompt, int highestNum);
	
};

