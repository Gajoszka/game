#include <iostream>
#include "DBconnection.h"
#include "MainMenu.h"


using namespace std;

int main()
{
    DBconnection connect;
    MainMenu start;
    start.user_choice();
    return 0;
}
