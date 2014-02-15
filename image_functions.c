#include "image_functions.h"

FILE* open_file(char* name) {
	FILE* file = fopen( name, "rb" );

	if( file == 0 ) {
		printf("File not found.\n");
		exit(1);
	}

	fflush(file);

	return file;
}


Image read_in(FILE* f) {
	int i, j;
	Image image;
	/* specify byte size of 4 in case we are running on a 16-bit architecture */
	fread( &(image.width),  4, 1, f );
	fread( &(image.height), 4, 1, f);

	image.pixels  = (Pixel**) malloc( image.width * sizeof(Pixel*) );
	
	for( i = 0; i < image.width; i++ ) {
		image.pixels[i] = (Pixel*) malloc( image.height * sizeof(Pixel) );
	}

	for( i = 0; i < image.width; i++ ) {
		for( j = 0; j < image.height; j++ ) {
			fread( &image.pixels[i][j].red,   sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].blue,  sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].green, sizeof(unsigned char), 1, f );
			fread( &image.pixels[i][j].alpha, sizeof(unsigned char), 1, f );
		}
	}

	return image;
}

void write_file(FILE* outfile, Image* pic) {
	int i, j;
	/* again, have to specify int size */
	fwrite( &(pic->width),  4, 1, outfile );
	fwrite( &(pic->height), 4, 1, outfile );

	for( i = 0; i < pic->width; i++ ) {
		for( j = 0; i < pic->height; j++ ) {
			fwrite( &(pic->pixels[i][j].red),   sizeof(unsigned char), 1, outfile );
			fwrite( &(pic->pixels[i][j].blue),  sizeof(unsigned char), 1, outfile );
			fwrite( &(pic->pixels[i][j].green), sizeof(unsigned char), 1, outfile );
			fwrite( &(pic->pixels[i][j].alpha), sizeof(unsigned char), 1, outfile );
		}
	}


}

void close_image(Image* image) {
	int i;
	for( i = 0; i < image->width; i++ ) {
		free( image->pixels[i] );
	}

	free( image->pixels[i] );
}
