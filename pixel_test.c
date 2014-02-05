#include "pixel_test.h"


int main(int argc, char** argv) {
	return 0;
}


int creation_test() {
	Pixel a, b;

	a.red = 50;
	a.blue = 100;
	a.green = 150;
	a.alpha = 200;

	b = *create_pixel(50, 100, 150, 200);

	return pixel_equals(&a, &b);
}

int grey_test() {
	Pixel a, b;

	a = *create_pixel(50, 100, 150, 200);
	black_and_white(&a);

	b.red = b.blue = b.green = 100;
	b.alpha = 200;

	return pixel_equals(&a, &b);
}


int pixel_equals(Pixel *a, Pixel *b) {
	return	a->red == b->red &&
			a->blue == b->blue &&
			a->green == b->green &&
			a->alpha == b->alpha;	
}
