#include "pixel_functions.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

Pixel create_pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	Pixel temp;
	temp.red = r;
	temp.green = g;
	temp.blue = b;
	temp.alpha = a;
	
	return temp;	
}	

void black_and_white(Pixel *p) {
	double average =( (double) (p->red + p->blue + p->green) )/3;
	unsigned char rounded_average = round( average );
	p->red = p->blue = p->green = average;
}

void overlay(Pixel *a, Pixel *b) {
	Pixel temp;

	temp.red =   calculate_color(a->red, b->red, a->alpha, b->alpha);
	temp.blue =  calculate_color(a->blue, b->blue, a->alpha, b->alpha);
	temp.green = calculate_color(a->green, b->green, a->alpha, b->alpha);
	temp.alpha = (unsigned char) lround( (double) b->alpha + a->alpha * (255- b->alpha) / 255 );

	*a = temp;
}

unsigned char calculate_color(unsigned char r1, unsigned char r2, unsigned char a1, unsigned char a2) {
	return (unsigned char) lround( a2 * r2 /255. + a1* r1* (255-a2)/ 255/ 255);
}

void color_shift(Pixel *p, char* pattern) {
	unsigned char t;
	
	if( strcmp( pattern, "RG" ) || strcmp( pattern, "GR" ) ) {
		swap_colors( &p->red, &p->green);
	} if( strcmp( pattern, "RB" ) || strcmp( pattern, "BR" ) ) {
		swap_colors( &p->red, &p->blue );
	} if( strcmp( pattern, "GB" ) || strcmp( pattern, "BG" ) ) {
		swap_colors( &p->green, &p->blue );
	} if( strcmp( pattern, "RGB" ) || strcmp( pattern, "GBR" ) || strcmp( pattern, "BRG" ) ) {
		triple_swap( &p->red, &p->green, &p->blue );
	} if( strcmp( pattern, "RBG" ) || strcmp( pattern, "BGR" ) || strcmp( pattern, "GRB" ) ) {
		triple_swap( &p->red, &p->blue, &p->green );
	} else {
		/* TODO: error case */
		printf("Error case\n");
	}

}

void swap_colors(unsigned char *a, unsigned char *b) {
	unsigned char t  = *a;
	*a = *b;
	*b = t;
}

void triple_swap( unsigned char *a, unsigned char *b, unsigned char *c ) {
	unsigned char t = *a;
	*a = *c;
	*b = *a;
	*c = t;
}

