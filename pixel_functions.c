#include "pixel_functions.h"

void black_and_white(Pixel *p) {
	Pixel temp;
	unsigned char average = (p->red + p->blue + p->green)/3;

	temp.red = temp.blue = temp.green = average;
	*p = temp;
}

void overlay(Pixel *a, Pixel *b) {
	Pixel temp;

	temp.red =   calculate_color(a->red, b->red, a->alpha, b->alpha);
	temp.blue =  calculate_color(a->blue, b->blue, a->alpha, b->alpha);
	temp.green = calculate_color(a->green, b->green, a->alpha, b->alpha);
	temp.alpha = b->alpha + a->alpha * (255- b->alpha) / 255;

	*a = temp;
}


unsigned char calculate_color(unsigned char r1, unsigned char r2, unsigned char a1, unsigned char a2) {
	return (r2 * a2)/255 + a1 * (255 - a2) * r1 / 255 / 255;
}

