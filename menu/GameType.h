#pragma once
#include <type_traits>
#include <xiosbase>
#include <functional>
#include "GameDef.h"
#include <string>
using namespace std;


// creating new types - functions
typedef function<void(int column, int row, char icon)> printElement;

typedef function<RoomElement*(int column, int row)> getElement;

typedef function<void(messageType type, string msg)> printMessage; //messageType - in which frame/window

template<typename Base, typename T>

inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

