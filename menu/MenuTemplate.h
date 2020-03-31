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
	string nameMenu();
private:
	int chooseIndex(string head, vector<string> options, string prompt);
	int getValidInput(string prompt, int highestNum);
	
};

