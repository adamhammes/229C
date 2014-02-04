pixel_functions.c : pixel.h pixel_functions.h
	gcc -ansi -pedantic -c pixel_functions.c

pixel_functions.h : pixel.h
	gcc -ansi -pedantic pixel_functions.h

clean:
	rm *.o rm *.h.gch mixel_functions.c
