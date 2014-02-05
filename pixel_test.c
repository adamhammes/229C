#include "pixel_test.h"

int pixel_equals(Pixel *a, Pixel *b) {
	return	a->red == b->red &&
			a->blue == b->blue &&
			a->green == b->green &&
			a->alpha == b->alpha;	
}
