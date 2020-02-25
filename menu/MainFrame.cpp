#include "MainFrame.h"

void MainFrame::printInside()
{
	(*getRoom()).print(getTopLeft().getColumn()+ 2, getTopLeft().getRow() + 2);
}
