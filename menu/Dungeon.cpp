#include "dungeon.h"
#include "keyfunctions.h"
#include "Screen.h"
#include <string>
#include <iostream>


using namespace std;

void Dungeon::test1() {
	gotoxy(x, y);
	string multitable[10][5];
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 5; ++j) {
			multitable[i - 1][j - 1] = "*";
			cout << multitable[i - 1][j - 1] << "\t";
		}
		cout << endl;
	}
	KeyFunctions go;
	go.movement();


}