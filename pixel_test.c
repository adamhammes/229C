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

	a = *create_pixel(50, 100, 150, 100);
	black_and_white(&a);
	/* b has correct values */
	b.red = b.blue = b.green = b.alpha = 100;

	return pixel_equals(&a, &b);
}

int overlay_test() {
	Pixel a, b, c;

	a = *create_pixel(50, 100, 150, 200);
	b = *create_pixel(200, 150, 100, 50);

	overlay(&a, &b);
	c = *create_pixel(70, 92, 114, 210);

	return pixel_equals(&a, &c);
}


int pixel_equals(Pixel *a, Pixel *b) {
	return	a->red == b->red &&
			a->blue == b->blue &&
			a->green == b->green &&
			a->alpha == b->alpha;	
}
