#include "Stats.h"
#include "Frame.h"
#include "Screen.h"
#include <iostream>

using namespace std;

void Stats::frame() {
    Frame stats;
    stats.printFrame(46, 1, 20, 15);
   // gotoxy(48, 1);
   // for (int i = 48; i < width + 2; i++) {
   //         cout << "#";
   // }
   ///* cout << endl;*/

   // for (int i = 0; i < height; i++) {
   //     for (int j = 49; j < width + 21; j++) {
   //         if (j == width)
   //             cout << "#";

   //        if (j == width + 20)
   //             cout << "#";
   //     }
   //     cout << endl;
   // }
   // for (int i = 0; i < width + 2; i++) {
   //     cout << "#";
   // }
   // cout << endl;
}