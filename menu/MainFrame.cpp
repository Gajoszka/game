#include "MainFrame.h"

void MainFrame::printInside()
{
	(*getRoom()).print(getTop().getX()+ 2, getTop().getY() + 2);
}
