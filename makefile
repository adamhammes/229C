all: bw colorshift crop overlay

clean : 
	rm *.o all

overlay : overlay.o image_functions.o pixel_functions.o
	gcc -o overlay overlay.o image_functions.o pixel_functions.o -lm

overlay.o : overlay.c image_functions.o
	gcc -ansi -pedantic -c overlay.c

crop : crop.o image_functions.o pixel_functions.o
	gcc  -o crop crop.o image_functions.o pixel_functions.o -lm

crop.o : crop.c image_functions.o
	gcc -ansi -pedantic -c crop.c

colorshift : image_functions.o colorshift.o pixel_functions.o
	gcc -o colorshift colorshift.o image_functions.o pixel_functions.o -lm

colorshift.o : colorshift.c image_functions.o
	gcc -ansi -pedantic -c colorshift.c

bw : image_functions.o bw.o pixel_functions.o
	gcc -o bw bw.o image_functions.o pixel_functions.o -lm

pixel_functions.o : pixel_functions.h pixel_functions.c pixel.h
	gcc -ansi -pedantic -c pixel_functions.c

bw.o : bw.c image_functions.o
	gcc -ansi -pedantic -c bw.c

image_functions.o : image_functions.c image_functions.c pixel_functions.o
	gcc -ansi -pedantic -c image_functions.c
