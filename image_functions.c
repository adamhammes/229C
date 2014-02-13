#include "image_functions.h"
#include <stdlib.h>


Image read_in(FILE* f) {
	int width, height, i, j;
	Image image;
	/* specify byte size of 4 in case we are running on a 16-bit architecture */
	fread( &width,  4, 1, f );
	fread( &height, 4, 1, f);

	image.pixels  = (Pixel**) malloc( width * sizeof(Pixel*) );
	
	for( i = 0; i < width; i++ ) {
		image.pixels[i] = (Pixel*) malloc( height * sizeof(Pixel) );
	}

	for( i = 0; i < width; i++ ) {
		for( j = 0; j < height; j++ ) {
			fread( &image.pixels[i][j].red,   sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].blue,  sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].green, sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].alpha, sizeof(unsigned char), 1, f );
		}
	}

	return image;
}

void close_Image(Image* image) {
	int i;
	for( i = 0; i < image->width; i++ ) {
		free( image->pixels[i] );
	}

	free( image->pixels[i] );
}
