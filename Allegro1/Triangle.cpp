#include "Triangle.h"

using namespace std;

Triangle::Triangle(int offset_x, int offset_y, int x1, int y1, int x2, int y2, int x3, int y3, const int color) : IFig(offset_x, offset_y, color){
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
}

Triangle::Triangle(ifstream & creationStream) : IFig(creationStream){
	creationStream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

void Triangle::draw(int dx = 0, int dy = 0){
	triangle(screen, x1+dx+X(), y1+dy+Y(), x2+dx+X(), y2+dy+Y(), x3+dx+X(), y3+dy+Y(), this->getColor());
}

string Triangle::toString(){
	stringstream ss;
	ss << "Triangle\n";
	ss << X() << " " << Y() << " " << getColor() << "\n";
	ss << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
	return ss.str();
}