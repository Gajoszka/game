#pragma once
class RoomElement {
public:
	RoomElement(int id, char icon, bool canPass,int score) {
		this->id = id;
		this->icon = icon;
		this->canPass = canPass;
		this->score = score;
	}
	virtual int getId() {
		return id;
	}
	int id = 0;
	int score = 0;
	char icon = ' ';
	bool canPass=true;
};

