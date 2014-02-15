all: bw

clean : 
	rm *.o bw

pixel_functions.o : pixel_functions.c pixel_functions.h pixel.h
	gcc -ansi -pedantic -c pixel_functions.c -lm

bw : image_functions.o bw.o pixel_functions.o
	gcc -ansi -pedantic -o bw bw.o image_functions.o pixel_functions.o -lm

pixel_functions.o : pixel_functions.h pixel_functions.c pixel.h
	gcc -ansi -pedantic -c pixel_functions.c -lm

bw.o : bw.c image_functions.o
	gcc -ansi -pedantic -c bw.c -lm

image_functions.o : image_functions.c image_functions.c pixel_functions.o
	gcc -ansi -pedantic -c image_functions.c -lm
