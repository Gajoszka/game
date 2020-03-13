#pragma once
#include <type_traits>
#include <xiosbase>
#include <functional>
#include "GameDef.h"
#include <string>
using namespace std;

// creating new types - functions
typedef function<void(int column, int row, char icon)> printElement;

typedef function<void(messageType type, string msg)> printMessage; //messageType - in which frame/window