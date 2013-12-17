#include "IFig.h"

IFig::IFig(int x = 0, int y = 0, const int col = 0xFFFF) : color(col){
	this->x = x;
	this->y = y;
}

IFig::IFig(ifstream & creationStream){
	creationStream >> x >> y >> color;
}

int& IFig::X(){ return x; }
int& IFig::Y(){ return y; }
int& IFig::getColor() { return color; }