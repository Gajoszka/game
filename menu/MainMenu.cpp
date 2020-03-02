#include "MainMenu.h"
#include "GameManager.h"
#include "Screen.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

MainMenu::MainMenu() :Frame(40,10) {
}

// manu options
void MainMenu::printInside() {
	menu_options.push_back(new_game);
	menu_options.push_back(keys);
	menu_options.push_back(scores);
	menu_options.push_back(exit);
	/*for (int i = 0; i < menu_options.size(); i++) {
		printLine(i+2, menu_options[i]);
	}
	printLine(8, "Which option do you choose? ");*/
	showMenu();
}

// creating user for a current game
void MainMenu::play(string name) {
	GameManager game;
	Player player(name);
	game.play(&player);
}


// taking username and putting it into database
void MainMenu::intro()
{
	system("CLS"); // cleat the screen
	printFrame();
	string name;
	printCenterLine(2, "Welcome to the game!");
	printLine(5,"What's your name? ");
	cin >> name;
	//store name, so it cann be added to database with a score
	system("CLS");
	play(name);	
}

void MainMenu::key_fun()
{
	system("CLS");
	printFrame();
	db.key_functions();
}

// taking user input and proceeding chosen action
void MainMenu::user_choice()
{
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
	case 4: cout << "Exit" << endl;
	}
}

int MainMenu::chooseIndex(string head, vector<string> options, string prompt) {
	int highestNumber = menuDisplay(head, options);
	int choice = getValidInput(prompt + " (from 1 to " + to_string(highestNumber) + "): ", highestNumber);
	return choice;
}

string MainMenu::chooseOption(string head, vector<string> options, string prompt) {
	int highestNumber = menuDisplay(head, options);
	int choice = getValidInput(prompt + " (from 1 to " + to_string(highestNumber) + "): ", highestNumber);
	return options[choice - 1];
}

int MainMenu::menuDisplay(string head, vector<string>options) {
	if (head.size() > 0) {
		nameDisplay(head);
	}
	for (int index = 0; index < options.size(); index++) {
		showMenuLine(index + 1, options[index]);
	}

	return options.size();
}

void MainMenu::nameDisplay(string name) {
	if (name != " ") {
		cout << "\t" + name + "\n";
	}
}


void MainMenu::showMenuLine(int index, string text) {
	cout << index + ". " + text;
}

int MainMenu::getValidInput(string prompt, int highestNum) {
	bool invalid_answer = false;
	while (invalid_answer == false) {
		string user_choice = prompt;
		cin >> prompt;
		try {
			if (user_choice.size() > 0) { // takes first character from user input
				answer = int(user_choice[0]);
			} else {
				answer = -1;
			}
		}
		catch (exception) {
			answer = -1;
			invalid_answer = answer > 0 and answer <= highestNum;
		}
	}

	return answer;
}

void MainMenu::showMenu() {  // self ?????
	while (active) {  
		string choice = chooseOption("Menu", menu_options, "Please choose option ");
		if (choice == new_game) {
			intro();
		}
		else if (choice == keys) {
			key_fun();
		}
		else if (choice == scores) {
			cout << "Score board" << endl;
		}
		else if (choice == exit) {
			cout << "Exit" << endl;
			active = false;
		}
	}
}