#include "pixel_test.h"
#include <stdio.h>

int main(int argc, char** argv) {
	if( creation_test() )
		printf("Pixel creation worked correctly!\n");
	 else
		printf("Pixel creation failed.\n");

	if( grey_test() )
		printf("Black and white conversion worked!\n");
	else 
		printf("Black and white conversion failed.\n");

	if( overlay_test() )
		printf("Pixel overlay ran successfully!\n");
	else 
		printf("Pixel overlay failed.\n");
}


int creation_test() {
	Pixel a, b;
	int toReturn;

	a = create_pixel(50, 100, 150, 200);

	b.red = 50;
	b.green = 100;
	b.blue = 150;
	b.alpha = 200;
	
	toReturn = pixel_equals(&a, &b);


	return toReturn;
}

int grey_test() {
	Pixel a, b;
	int toReturn;

	a = create_pixel(50, 100, 150, 100);
	black_and_white(&a);
	b.red = b.blue = b.green = b.alpha = 100;

	toReturn = pixel_equals(&a, &b);

	return toReturn;
}

int overlay_test() {
	Pixel a, b, c;
	int toReturn;

	a = create_pixel(50, 100, 150, 200);
	b = create_pixel(200, 150, 100, 50);

	overlay(&a, &b);
	c = create_pixel(70, 92, 114, 210);


	toReturn = pixel_equals(&a, &c);

	return toReturn;
}

int pixel_equals(Pixel *a, Pixel *b) {
	int toReturn = 1;
	
	if( a->red != b->red ) {
		printf("a.red was %d, supposed to be %d.\n", a->red, b->red);
		toReturn = 0;
	}
	
	if( a->blue != b-> blue ) {
		printf("a.blue was %d, supposed to be %d.\n", a->blue, b->blue);
		toReturn = 0;
	}

	if( a->green != b->green ) {
		printf("a.green was %d, supposed to be %d.\n", a->green, b->green);
		toReturn = 0;
	}
		
	if( a->alpha != b->alpha ) {
		printf("a.alpha was %d, supposed  to be %d.\n", a->alpha, b->alpha);
		toReturn = 0;
	}

	return toReturn;
}
