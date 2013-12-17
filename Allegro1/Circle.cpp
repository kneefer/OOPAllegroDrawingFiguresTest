#include "Circle.h"

using namespace std;

Circle::Circle(int offset_x, int offset_y, int x, int y, int radius, const int color) : IFig(offset_x, offset_y, color){
	this->x = x;
	this->y = y;
	this->radius = radius;
}

Circle::Circle(ifstream & creationStream) : IFig(creationStream){
	creationStream >> x >> y >> radius;
}

void Circle::draw(int dx = 0, int dy = 0){
	circlefill(screen, x+dx+X(), y+dy+Y(), radius, this->getColor());
}

string Circle::toString(){
	stringstream ss;
	ss << "Circle\n";
	ss << X() << " " << Y() << " " << getColor() << "\n";
	ss << x << " " << y << " " << radius << "\n";
	return ss.str();
}
