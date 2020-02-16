#include "MainMenu.h"
#include "GameMain.h"
#include "KeyFunctions.h"
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

MainMenu::MainMenu() {

	vector<string> menu_options;
	menu_options.push_back("1. Start new game");
	menu_options.push_back("2. Key functions");
	menu_options.push_back("3. Score board");
	menu_options.push_back("4. Exit");
	for (int i = 0; i < menu_options.size(); i++) {
		cout << menu_options[i] << endl;
	}
	user_choice();
}


void MainMenu::user_choice()
{
	int choice;
	GameMain intro;
	KeyFunctions obj;
	cout << "Which option do you choose?";
	cin >> choice;
	switch (choice) {
	case 1: intro.GameIntro();
		break;
	case 2: obj.connection();
		break;
	case 3: cout << "Score board" << endl;
		break;
	case 4: cout << "Exit" << endl;
	}
}

MainMenu::~MainMenu() {

}