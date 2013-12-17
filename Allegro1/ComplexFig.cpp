#include "ComplexFig.h"

using namespace std;

void ComplexFig::AddFig(IFig* fig){
	_figs.push_back(fig);
}

void ComplexFig::draw(int dx, int dy){
	for(int i=0; i<_figs.size(); ++i){
		_figs[i]->draw(dx, dy);
	}
}

void ComplexFig::save(){
	stringstream ss;

	for(int i=0; i<_figs.size(); ++i){
		ss << _figs[i]->toString();
	}
	string stringWithSavedFigures = ss.str();

	ofstream fileToSave;
	fileToSave.open(FILE_TO_SAVE, ofstream::out);
	fileToSave << stringWithSavedFigures;
	fileToSave.close();
}

void ComplexFig::open(){
	ifstream fileToLoadFrom;
	string nameOfFigure;

	fileToLoadFrom.open(FILE_TO_SAVE, ifstream::in);
    if(!fileToLoadFrom.good()) return;

	while(true){
		fileToLoadFrom >> nameOfFigure;
		if(!fileToLoadFrom.good()) break;

		if (nameOfFigure.compare("Rectangle") == 0)
			AddFig(new Rect(fileToLoadFrom));
		else if (nameOfFigure.compare("Triangle") == 0)
			AddFig(new Triangle(fileToLoadFrom));
		else if (nameOfFigure.compare("Circle") == 0)
			AddFig(new Circle(fileToLoadFrom));
	}

	fileToLoadFrom.close();
}

ComplexFig::~ComplexFig(){
	for(int i=0; i<_figs.size(); ++i)
		delete _figs[i];
}