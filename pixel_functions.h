#include "pixel.h"

Pixel create_pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void black_and_white(Pixel *p);
unsigned char calculate_color(unsigned char r1, unsigned char r2, unsigned char a1, unsigned char a2);
void color_shift(Pixel *p, char *pattern);
void overlay(Pixel *a, Pixel *b);
