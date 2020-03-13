#pragma once

#include "RoomElement.h"
#include "Treasure.h"

#define sign_wall  static_cast<char>(186);
#define sign_top_right static_cast<char>(187);
#define sign_top_left static_cast<char>(201);
#define sign_bottom_right static_cast<char>(188);
#define sign_bottom_left static_cast<char>(200);
#define sign_dash static_cast<char>(205);

const char sign_enemy = 'E';
const char sign_player = '@';
const char sign_shot = '.';


const RoomElement p_room_wall = RoomElement(1, 219, false, 0);
const RoomElement p_room_door = RoomElement(-1, ' ', true, 5);
const RoomElement p_room_scale = RoomElement(2, static_cast<char>(178), false, 0);
//RoomElement* p_room_treasure= &RoomElement(3, static_cast<char>(158), true, 2) ;
const Treasure p_room_treasure = Treasure();
const RoomElement p_room_inner = RoomElement(0, ' ', true, 0);
const RoomElement p_failed = RoomElement(-11, ' ', false, 0);

enum  GameAction { endGame, exitRoom, Failed, moveEnemy, key_up, key_down, key_left, key_right, served };

enum  messageType { score, info };




