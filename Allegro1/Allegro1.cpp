#define USE_CONSOLE
#define FROM_SAVE 

#include "Allegro1.h"

#include <crtdbg.h>			// for checking
#define _CRTDBG_MAP_ALLOC   // memory leaks


using namespace std;

void wait(unsigned timeout){
	timeout += clock();
	while(clock() < timeout) continue;
}

int main()
{
	int j=0;

	allegro_init();
	install_keyboard();
	set_color_depth(24);
	set_gfx_mode(GFX_GDI,900,700,0,0);

	ComplexFig complex;

#ifndef FROM_SAVE // remove #define FROM_SAVE to avoid using file with vector save
	Triangle* triangle_1 = new Triangle(10, 0, 0, 50, 200, 50, 100, 10, 0xFF);
	Rect* rectangle_1 = new Rect(10, 0, 0, 60, 200, 200, 0xFFFF);
	Circle* circle_1 = new Circle(10, 220, 30, 0, 30, 0xFFA00F);
	Circle* circle_2 = new Circle(150, 220, 30, 0, 30, 0xFFA00F);

	complex.AddFig(triangle_1);
	complex.AddFig(rectangle_1);
	complex.AddFig(circle_1);
	complex.AddFig(circle_2);

	complex.save();
#endif

#ifdef FROM_SAVE // add #define FROM_SAVE to use file with vector save
	complex.open();
#endif

	for(int i=0; i<=615; i+=205){	// printing figures on screen horizontally
		complex.draw(i,0);
		wait(1000);
	}

	for(int i=200; i<=400; i+=200){	// printing figures on screen vertically
		complex.draw(615,i);
		wait(1000);
	}
	//complex.~ComplexFig();  // ucomment to check memory leaks
	//_CrtDumpMemoryLeaks();  // in output while debug
	return 0;
}

