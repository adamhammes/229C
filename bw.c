#include "image_functions.h"

int main( int argc, char** argv ) {
	int i, j;	
	FILE* infile;
	FILE* outfile;
	Image pic;
	
	if( argc <= 1 ) { /* no arguments given */
		exit(0);
	}	

	infile = open_file( argv[1] );

	pic = read_in( infile );

	for( i = 0; i < pic.width; i++ ) {
		for( j = 0; j < pic.height; j++ ) {
			black_and_white( &(pic.pixels[i][j]) );
		}
	}

	outfile = fopen( argv[2], "wb" );
	write_file( outfile, &pic );


	close_image( &pic );
	free( outfile );
	
	return 0;
}
