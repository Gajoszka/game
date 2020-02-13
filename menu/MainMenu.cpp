#include "MainMenu.h"
#include "GameMain.h"
#include "KeyFunctions.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <SDL.h>


using namespace std;

MainMenu::MainMenu() {

	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Main menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(200);*/

	vector<string> menu_options;
	menu_options.push_back("1. Start new game");
	menu_options.push_back("2. Key functions");
	menu_options.push_back("3. Score board");
	menu_options.push_back("4. Exit");
	for (int i = 0; i < menu_options.size(); i++) {
		cout << menu_options[i] << endl;
	}
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
