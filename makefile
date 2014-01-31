pixel_functions.c : pixel.h pixel_functions.h
	gcc -ansi -pedantic pixel_functions.c

clean:
	rm *.o rm *.h.gch mixel_functions.c
