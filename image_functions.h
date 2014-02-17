#include "image.h"
#include <stdio.h>
#include <stdlib.h>

FILE* open_file(char* name);
Image read_in(FILE* f);

void make_grey(Image* pic);
void make_funky(Image* pic, char* pattern);
void write_image(char* name, Image* pic);
void close_image(Image* i);
