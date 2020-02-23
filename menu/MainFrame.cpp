#include "MainFrame.h"

void MainFrame::printInside()
{
	(*getRoom()).print(getTop().getX()+ 1, getTop().getY() + 1);
}
