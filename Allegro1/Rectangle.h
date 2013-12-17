#pragma once

#include <cstdlib>
#include <iostream>
#include "allegro.h"
#include "IFig.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Rect : public IFig {
private:
	int x1, y1, x2, y2;
public:
	Rect(int offset_x, int offset_y, int x1, int y1, int x2, int y2, const int color);
	Rect(ifstream & creationStream);

	void draw(int dx, int dy);
	string toString();
};