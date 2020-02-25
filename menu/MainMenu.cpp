#include "MainMenu.h"
#include "GameManager.h"
#include "Screen.h"
//#include <iostream>
//#include <vector>
#include <iomanip>


using namespace std;
MainMenu::MainMenu() :Frame(40,10) {
	
}

void MainMenu::printInside() {
	vector<string> menu_options;
	menu_options.push_back("1. Start new game");
	menu_options.push_back("2. Key functions");
	menu_options.push_back("3. Score board");
	menu_options.push_back("4. Exit");
	for (int i = 0; i < menu_options.size(); i++) {
		printLine(i+2, menu_options[i]);
	}
	printLine(8, "Which option do you choose? ");
	user_choice();
}

void MainMenu::play(string name) {
	GameManager gra;
	Player player(name);
	gra.play(&player);
}

void MainMenu::intro()
{
	system("CLS");
	printFrame();
	string name;
	printCenterLine(2, "Welcome to the game!");
	printLine(5,"What's your name? ");
	cin >> name;
	//store name, so it cann be added to database with a score
	system("CLS");
	play(name);
	
}

void MainMenu::user_choice()
{
	int choice;
	//KeyFunctions obj;
	
	cin >> choice;
	switch (choice) {
	case 1: intro();
		break;
	case 2:
		//obj.connection();
		break;
	case 3: cout << "Score board" << endl;
		break;
	case 4: cout << "Exit" << endl;
	}
}
