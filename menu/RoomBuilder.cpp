#include "RoomBuilder.h"

Room RoomBuilder::build()
{

	generator();
	return Room(rows);
}


void RoomBuilder::generator() {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			rows[j][i] = 0;
		}
	}
	for (int i = 0; i < width; i++) {
		rows[0][i] = 1;
		rows[height-1][i] = 1;
	}

	for (int i = 0; i < height; i++) {
		rows[i][0] = 1;
		rows[i][width-1] = 1;
	}


	for (int i = 0; i < this->wallCount; i++) {
		int k = rand() % (height - 4);
		int size = rand() % (width - 10);
		for (int j = 0; j < size; j++) 
			rows[k][j] = 1;
	}
	for (int i = 0; i < this->wallCount; i++) {
		int k = rand() % (width - 4);
		int size = rand() % (height - 5);
		for (int j = 0; j < size; j++) 
			rows[j][k] = 1;
			
	}

	/*for (int i = 0; i < this->doorCount; i++) {
		int wall = rand() % (4);
		int size = rand() % (height - 5);
		for (int j = 0; j < size; j++)
			(&rows[i])[k] = 1;

	}*/

}
void genericDorr(int* map) {
	//Point p;
	//switch (rand()%4)
	//{case 0:
	//	
	//default:
	//	break;
	//} rand() % (4);
	//	int size = rand() % (height - 5);
	//	for (int j = 0; j < size; j++)
	//		(&rows[i])[k] = 1;

	//}
}


