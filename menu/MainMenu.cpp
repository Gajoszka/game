#include "MainMenu.h"
#include "GameManager.h"
#include "GameType.h"
#include "Screen.h"
#include <iostream>
#include <vector>
#include <iomanip>
/* Creating the opening menu*/
using namespace std;

MainMenu::MainMenu() :Frame(40, 10) {
}

// manu options
void MainMenu::printInside() {
	menu_options.push_back(new_game);
	menu_options.push_back(keys);
	menu_options.push_back(scores);
	menu_options.push_back(exit);
	showMenu();
}

// creating user for a current game
void MainMenu::play(string name) {
	GameManager game;
	game.play(name);
	printFrame();
}

// taking username and putting it into database
void MainMenu::intro()
{
	system("CLS"); // cleat the screen
	printFrame();
	string name = "";
	printCenterLine(2, "Welcome to the game!");
	printLine(5, "What's your name? ");
	char key=32; //32 = SPACE
	// username cannot escape the frame
	while (key != 13) { // 13 = ENTER
		key = _getch();
		if (name.size()<10 && key >= '0' && key <= 'z') {
			name += key;
			printLine(5, "What's your name? " + name);
		}
	}
	db.add_username(name);
	system("CLS");
	play(name);
}

// transfer to key functions
void MainMenu::key_fun()
{
	system("CLS");
	printFrame();
	db.key_functions();
}

// taking user input and proceeding chosen action
void MainMenu::user_choice()
{
	GameAction action;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: intro();
		break;
	case 2:
		key_fun();
		break;
	case 3: cout << "Score board" << endl;
		break;
	case 4: action = endGame;
	}
}

// choose option by index
int MainMenu::chooseIndex(string head, vector<string> options, string prompt) {
	int highestNumber = menuDisplay(head, options);
	int choice = getValidInput(prompt + "(from 1 to " + to_string(highestNumber) + "): ", highestNumber);
	return choice;
}

//choose option by name
string MainMenu::chooseOption(string head, vector<string> options, string prompt) {
	int choice = chooseIndex(head, options, prompt);
	return options[choice - 1];
}

//display menu
int MainMenu::menuDisplay(string head, vector<string> options) {
	if (head.size() > 0) {
		nameDisplay(head);
	}
	for (int index = 0; index < options.size(); index++) {
		printLine(index + 2, to_string(index + 1) + ". " + options[index]);
	}

	return options.size();
}

//display option name
void MainMenu::nameDisplay(string name) {
	if (name != " ") {
		printLine(1, name);
	}
}

// show whole option line
void MainMenu::showMenuLine(int index, string text) {
	cout << index + ". " + text;
}

// ensure input is valid, there is such option in menu
int MainMenu::getValidInput(string prompt, int highestNum) {
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

// chosen option transfers to appropriate actions
void MainMenu::showMenu() {
	while (active) {
		string choose = chooseOption("Menu", menu_options, "Please choose option");
		if (choose == new_game) {
			intro();
		}
		else if (choose == keys) {
			key_fun();
		}
		else if (choose == scores) {
			cout << "Score board" << endl;
		}
		else if (choose == exit) {
			cout << "Exit" << endl;
			active = false;
		}
	}
}