#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player::addScore(int s) {
	score = score + s;
	printMsg(messageType::score,to_string(score));
}
int Player::getScore() {
	return score;
}
string Player::getName() {
	return name;
}