#pragma once
#define FILE_TO_SAVE "savedFigures.txt"

#include <vector>
#include <sstream>
#include <fstream>
#include "IFig.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

class ComplexFig{
private:
	vector<IFig*> _figs;
public:
	void AddFig(IFig* fig);
	~ComplexFig();

	void draw(int dx, int dy);
	void save();
	void open();
};