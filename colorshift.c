#include "image_functions.h"

int main( int argc, char** argv ) {
	FILE* infile;
	Image pic;

	if( argc < 4 ) { /* invaled number of arguments */
		printf("Please enter all arguments.\n");
		exit(0);
	}

	infile = open_file( argv[1] );
	pic = read_in( infile );
	fclose( infile );

	make_funky( &pic, argv[3] );

	write_file( &pic, argv[2] );
	close_image( &pic );


	return 0;
}
