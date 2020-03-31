#include "MenuTemplate.h"
#include <iostream>
#include "Screen.h"


// choose option by index
int MenuTemplate::chooseIndex(string head, vector<string> options, string prompt) {
	height = options.size() + 5;
	width = max(head.size(), prompt.size());
	for (string element : options) {
		if (element.size() > width)
			width = element.size();
	}
	width += 20;
	this->topLeft.setColumn(10); topLeft.setRow(5);
	printFrame();
	printHeader(head);
	for (int index = 0; index < options.size(); index++) {
		printLine(index + 2, to_string(index + 1) + ". " + options[index]);
	}
	int choice = getValidInput(prompt + "(from 1 to " + to_string(options.size()) + "): ", options.size());
	return choice;
}

//choose option by name
string MenuTemplate::chooseOption(string head, vector<string> options, string prompt) {
	int choice = chooseIndex(head, options, prompt);
	return options[choice - 1];
}

string MenuTemplate::nameMenu()
{
	width = 30, height = 6;
	this->topLeft.setColumn(10); topLeft.setRow(5);
	printFrame();
	printHeader("Welcome to the game!");
	string name = "";
	printLine(3, "What's your name? ");
	char key=32; //32 = SPACE
	// username cannot escape the frame
	while (key != 13) { // 13 = ENTER
		key = _getch();
		if (name.size()<10 && key >= '0' && key <= 'z') {
			name += key;
			printLine(3, "What's your name? " + name);
		}
	}
	system("CLS");
	return name;
}

// ensure input is valid, there is such option in menu
int MenuTemplate::getValidInput(string prompt, int highestNum) {
	int answer = 0;
	string key;
	printLine(highestNum + 3, prompt);
	while (answer <= 0 or answer > highestNum) {
		key = _getch();
		try {
			answer = stoi(key); // makes an integer from a string
		}
		catch (exception) {
			answer = -1;
		}
	}
	return answer;
}

