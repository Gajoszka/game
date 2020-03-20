#include "DBconnection.h"
#include "Game.h"
/* Start of the game, connecting to database*/

using namespace std;

int main()
{
   DBconnection connect;
    Game game;
    game.start();
    return 0;
}
