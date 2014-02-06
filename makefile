pixel_test : pixel_test.o pixel_functions.o
	gcc -ansi -pedantic -o pixel_test pixel_test.o -lm

pixel_test.o : pixel_test.c pixel_test.h pixel_functions.o
	gcc -ansi -pedantic -c pixel_test.c -lm

pixel_functions.o : pixel_functions.c pixel_functions.h pixel.h
	gcc -ansi -pedantic -c pixel_functions.c -lm



