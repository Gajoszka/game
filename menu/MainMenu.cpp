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
void MainMenu::getOptions() {
	menu_options.push_back(new_game);
	menu_options.push_back(keys);
	menu_options.push_back(scores);
	menu_options.push_back(exit);
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
	play(menu.nameMenu());
}

// transfer to key functions
void MainMenu::key_fun()
{
	system("CLS");
	//printFrame();
	db.key_functions();
}

// chosen option transfers to appropriate actions
void MainMenu::showMenu() {
	system("CLS");
	getOptions();
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