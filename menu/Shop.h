#pragma once
#include "Frame.h"
#include <vector>
#include <string>
using namespace std;

class Shop : public Frame
{
public:
	Shop() : Frame(20, 10) {};
	void openShop();

private:
	vector<string> content;
};

