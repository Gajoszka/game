#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player::addScore(int s) {
	score = score + s;
}
int Player::getScore() {
	return score;
}
string Player::getName() {
	return name;
}