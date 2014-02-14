#include "image.h"
#include <stdio.h>

FILE* open_file(char* name);
Image read_in(FILE* f);
void close_Image(Image* i);
