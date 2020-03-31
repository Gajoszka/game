#include "MenuTemplate.h"
#include <iostream>
#include "Screen.h"


// choose option by index
int MenuTemplate::chooseIndex(string head, vector<string> options, string prompt) {
	height = options.size() + 3;
	width = max(head.size(), prompt.size());
	for (string element : options) {
		if (element.size() > width)
			width = element.size();
	}
	width += 3;
	if (head.size() > 0) {
		nameDisplay(head);
	}
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

void MenuTemplate::showOptions(vector<string> list)
{
	for (string el : list) {
		cout << el << endl;
	}
} 

//display option name
void MenuTemplate::nameDisplay(string name) {
	if (name != " ") {
		printLine(1, name);
	}
}

// show whole option line
void MenuTemplate::showMenuLine(int index, string text) {
	cout << index + ". " + text;
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

