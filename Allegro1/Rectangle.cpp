#include "Rectangle.h"

using namespace std;

Rect::Rect(int offset_x, int offset_y, int x1, int y1, int x2, int y2, const int color) : IFig(offset_x, offset_y, color){
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

Rect::Rect(ifstream & creationStream) : IFig(creationStream){
	creationStream >> x1 >> y1 >> x2 >> y2;
}

void Rect::draw(int dx = 0, int dy = 0){
	rectfill(screen, x1+dx+X(), y1+dy+Y(), x2+dx+X(), y2+dy+Y(), this->getColor());
}

string Rect::toString(){
	stringstream ss;
	ss << "Rectangle\n";
	ss << X() << " " << Y() << " " << getColor() << "\n";
	ss << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	return ss.str();
}