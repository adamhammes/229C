#include "pixel_functions.h"

void black_and_white(Pixel *p) {
	Pixel temp;
	int average = (p->red + p->blue + p->green)/3;

	temp.red = temp.blue = temp.green = average;
	*p = temp;
}
