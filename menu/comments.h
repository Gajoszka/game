#pragma once
class comments
{
	//#include <SDL.h>
	/*SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(3000);*/
};




//#include "Dungeon.h"
//#include<iostream>
//#include <stdlib.h>
//#include <vector>
//#include <random>
//
//using namespace std;
//
//random_device rd;
//mt19937 mt(rd());
//
//
//int Dungeon::randomInt(int min, int max) {
//	uniform_int_distribution<> dist(0, max - min);
//	return dist(mt) + min;
//}
//
//void Dungeon::createRoom(int x, int y, Directions dir, bool firstRoom = false) {
//	const int minRoomSize = 5;
//	const int maxRoomSize = 15;
//
//	Rect room;
//	room.width = randomInt(minRoomSize, maxRoomSize);
//	room.height = randomInt(minRoomSize, maxRoomSize);
//
//	if (dir == North) {
//		room.x = x - room.width / 2;
//		room.y = y - room.height / 2;
//	}
//	else if (dir == South) {
//		room.x = x - room.width / 2;
//		room.y = y + 1;
//	}
//
//	else if (dir == West) {
//		room.x = x - room.width;
//		room.y = y - room.height / 2;
//	}
//
//	else if (dir == East) {
//		room.x = x + 1;
//		room.y = y - room.height / 2;
//	}
//}




//#ifndef DUNGEON_H
//#define DUNGEON_H
//#include <vector>
//
//
//class Dungeon
//{
//	public:
//		struct Rect {
//			int x, y;
//			int width, height;
//		};
//		enum Tile {
//			floor = '.',
//			wall = '#',
//			door = '=',
//			staircase='>'
//		};
//		enum Directions {
//			North,
//			South,
//			West,
//			East
//		};
//
//		int randomInt(int min, int max);
//
//	private:
//		/*int _width, _height;
//		vector <char> _tiles;
//		vector <Rect> _rooms;
//		vector <Rect> exits;*/
//
//		void createRoom(int x, int y, Directions dir, bool firstRoom = false);
//};
//
//#endif //DUNGEON_H