#pragma once
#include <type_traits>
#include <xiosbase>
#include <functional>
#include "GameDef.h"
#include <string>
using namespace std;


typedef std::function<void(int column, int row, char icon)> printElement;

typedef std::function<void(messageType type, string msg)> printMessage;
