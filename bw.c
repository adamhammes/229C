#include "image_functions.h"

int main( int argc, char** argv ) {
	FILE* infile;
	Image pic;
	
	if( argc <= 1 ) { /* no arguments given */
		exit(0);
	}	

	infile = open_file( argv[1] );
	pic = read_in( infile );
	fclose( infile );
	
	make_grey( &pic );
	write_file( &pic, argv[2] );
	close_image( &pic );
	return 0;
}
