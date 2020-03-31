#include "MainMenu.h"
#include "GameManager.h"
#include "GameType.h"
#include "Screen.h"
#include <iostream>
#include <vector>
#include <iomanip>
/* Creating the opening menu*/
using namespace std;


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
	game.timerStart();
	game.play(name);
	showMenu();
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

// chosen option transfers to appropriate actions
void MainMenu::showMenu() {
	while (active) {
		string choose = menu.chooseOption("Menu", menu_options, "Please choose option");
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