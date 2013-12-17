#pragma once

#include <cstdlib>
#include <iostream>
#include "allegro.h"
#include "IFig.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Circle : public IFig {
private:
	int x, y, radius;
public:
	Circle(int offset_x, int offset_y, int x, int y, int radius, const int color);
	Circle(ifstream & creationStream);

	void draw(int dx, int dy);
	string toString();
};