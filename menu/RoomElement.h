#pragma once
class RoomElement {
public:
	RoomElement(int id, char icon, bool canGo,int score) {
		this->id = id;
		this->icon = icon;
		this->canGo = canGo;
		this->score = score;
	}
	int id = 0;
	int score = 0;
	char icon = ' ';
	bool canGo=true;
};

