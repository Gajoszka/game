#include "dungeon.h"
#include "Frame.h"
#include "keyfunctions.h"
#include "Stats.h"
#include "Screen.h"
#include <vector>
#include <iostream>


using namespace std;

void Dungeon::test1() {

    Frame room;
    room.printFrame(1, 1, 45, 15);
	//gotoxy(x, y);
 //   for (int i = 0; i < width + 2; i++) {
 //       if (i == 20) //make range for entrances/exits at top
 //           cout << " ";
 //       else
 //           cout << "#";
 //   }
 //   cout << endl;

 //   for (int i = 0; i < height; i++) {
 //       for (int j = 0; j < width; j++) {
 //           if (j == 0)
 //               cout << "#";

 //           cout << " ";

 //           if (j == width - 1)
 //               cout << "#";
 //       }
 //       cout << endl;
 //   }
 //   for (int i = 0; i < width + 2; i++) {
 //       cout << "#";
 //   }
 //   cout << endl;

	//
 //   Stats st;
 //   st.frame();
 //   //cout << "@";
	////go.movement();


}