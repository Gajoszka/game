#pragma once

#define sign_wall  static_cast<char>(186);
#define sign_top_right static_cast<char>(187);
#define sign_top_left static_cast<char>(201);
#define sign_bottom_right static_cast<char>(188);
#define sign_bottom_left static_cast<char>(200);
#define sign_dash static_cast<char>(205);

const char sign_enemy='E';
const char sign_player = '@';
const char sign_shot = '.';

 enum  GameAction { endGame , exitRoom , Failed , moveEnemy , key_up , key_down , key_left , key_right , served };

 enum  messageType{score, info};

