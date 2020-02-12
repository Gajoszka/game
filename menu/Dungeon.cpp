#include "Dungeon.h"
#include<iostream>
#include <stdlib.h>

using namespace std;

Dungeon::Dungeon() {
	const char room[2] = { '#', '.' };
	char level[15][15];               // ctrl+c+k a potem ctrl+k+u
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j <= 15; j++) {
			cout << level[room[rand() % 2]][room[rand() % 2]];
		}
	}

	
	
}

void Dungeon::print() {
	//cout << wall or floor;
}
