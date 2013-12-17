#pragma once

#include <cstdlib>
#include <iostream>
#include "allegro.h"
#include "IFig.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Triangle : public IFig {
private:
	int x1, y1, x2, y2, x3, y3;
public:
	Triangle(int offset_x, int offset_y, int x1, int y1, int x2, int y2, int x3, int y3, const int color);
	Triangle(ifstream & creationStream);

	void draw(int dx, int dy);
	string toString();
};