#pragma once

#define sign_wall  static_cast<char>(186);
#define sign_top_right static_cast<char>(187);
#define sign_top_left static_cast<char>(201);
#define sign_bottom_right static_cast<char>(188);
#define sign_bottom_left static_cast<char>(200);
#define sign_dash static_cast<char>(205);

const char sign_enemy = 'E';
const char sign_player = '@';
const char sign_shot = '.';

const int id_player = 50;
const int id_inner = 0;
const int id_wall = 1;
const int id_scale = 2;
const int id_door = -1;
const int id_treasure = 11;

enum  GameAction { endGame, exitRoom, Failed, moveEnemy, key_up, key_down, key_left, key_right, served,can_move,stop };

enum  messageType { score, info };