#include "MainFrame.h"

void MainFrame::printInside()
{
	if (getRoom() != nullptr)
		(*getRoom()).print(getTopLeft().getColumn() + 2, getTopLeft().getRow() + 2);
}
