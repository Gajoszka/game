#pragma once
/* defining constants*/

// defining special keys
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79
#define KEY_SPACE 32
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F10 68

// defining sing for wall creation
#define sign_wall  static_cast<char>(186);
#define sign_top_right static_cast<char>(187);
#define sign_top_left static_cast<char>(201);
#define sign_bottom_right static_cast<char>(188);
#define sign_bottom_left static_cast<char>(200);
#define sign_dash static_cast<char>(205);

// defining constants
const char sign_enemy = 'E';
const char sign_player = '@';
const char sign_shot = '.';

const int id_player = 50;
const int id_inner = 0;
const int id_wall = 1;
const int id_scale = 2;
const int id_door = -1;
const int id_treasure = 11;
const int id_gun_min = 100;
const int id_enemy_min = 1000;

enum  GameAction { buy_ammunition,endGame, exitRoom,fire, Failed,none, moveEnemy, key_up, key_down, key_left, key_right,player_death,served,can_move,stop };

enum  messageType { score, info,info_delay,
	ammunition,lives
};