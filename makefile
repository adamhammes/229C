all: bw colorshift crop overlay

cr_test : crop
	rm -f c_insanity.simp CR.simp insanity.simp
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/insanity.simp >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/c_insanity.simp >/dev/null 2>&1
	./valgrind --leak-check-yes./crop insanity.simp CR.simp 150 112 220 290
	./compare CR.simp c_insanity.simp
	rm CR.simp c_insanity.simp insanity.simp

bw_test: bw
	rm -f attached.*
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/attached.simp >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/bw_attached.simp >/dev/null 2>&1
	./bw attached.simp BW.simp
	./valgrind --leak-check-yes ./compare BW.simp bw_attached.simp
	rm -f BW.simp bw_attached.simp attached.simp

cs_test: colorshift
	rm -f *keanu*
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanu.simp >/dev/null 2>&1 
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanurgb.simp >/dev/null 2>&1 
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanurbg.simp >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanurg.simp  >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanurb.simp  >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/keanugb.simp >/dev/null 2>&1
	./colorshift keanu.simp rgb.simp RGB
	./colorshift keanu.simp rbg.simp RBG
	./colorshift keanu.simp rg.simp RG
	./colorshift keanu.simp rb.simp RB
	./valgrind --leak-check-yes ./colorshift keanu.simp gb.simp GB
	./compare rgb.simp keanurgb.simp
	./compare rbg.simp keanurbg.simp
	./compare rg.simp keanurg.simp
	./compare rb.simp keanurb.simp
	./compare gb.simp keanugb.simp
	rm -f *rbg.simp *rbg.simp *rg.simp *gb.simp *rb.simp keanu.simp

ov_test : overlay
	rm -f insanity.* doge.* insanedoge.*
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/doge.simp >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/insanity.simp >/dev/null 2>&1
	wget --no-check-certificate http://orion.math.iastate.edu/dstolee/229/project1/c_insanity.simp >/dev/null 2>&1
	./valgrind --leak-check-yes ./crop insanity.simp OV.simp 150 112 220 290
	./compare OV.simp c_insanity.simp

tarball : bw colorshift crop overlay
	make clean
	tar czf hammesa.tar.gzip *.c *.h README makefile

clean : 
	rm -f *.o bw colorshift crop overlay

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
