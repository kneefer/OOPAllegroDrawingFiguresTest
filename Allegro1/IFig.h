#pragma once

#include <cstdlib>
#include <iostream>
#include "allegro.h"
#include <fstream>

using namespace std;

class IFig
{
private:
	int x, y, const color;
public:
	IFig(int x, int y, const int col);
	IFig(ifstream & creationStream);
	virtual ~IFig() {}

	virtual void draw(int dx, int dy) = 0;
	virtual string toString() = 0;

	int& X();
	int& Y();
	int& getColor();
};