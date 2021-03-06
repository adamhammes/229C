Name:  Adam Hammes
NetID: hammesa@iastate.edu


Technical description:

The struct Pixel holds the RGBA values; Pixels are held in a dynamically-allocated array, part of an Image struct which additionally holds the height and width of the image.


Assumptions:

Because of the academic nature of this project, I took several liberties with my assumptions. My only protection against faulty command line arguments is checking that the number of arguments is correct, and this is done purely for my own sake; I don’t anticipate having to sanitize my arguments.

For overlay and crop, if the start index is out of bounds the original image is passed through with no changes; if the specified borders fall partially outside of the image, then the “hanging” borders are ignored. My reasoning behind this is that this behavior is what is desired in part B, and it is (entirely coincidentally) very easy to implement. 

Finally, for color_shift, if an incorrect pattern is given, then the output file is the same as the input file.
 

Source Files:

pixel.h			defines struct that I store pixels in
pixel_functions.h	header file for pixel_functions.c
pixel_functions.c	contains functions that work pixels- black_and_white, 
			overlay, etc.

image.h			defines struct that holds image pixels and height/width
image_functions.h	header file for image_functions.c; 
image_functions.c	calls pixel functions on images and handles image i/o

crop.c			crop main method
bw.c			black and white main method
overlay.c		overlay main method
colorshift.c		color shift main method



Design Decisions:

I tried to approach my executables from a pixel up perspective. I wrote my pixel_functions file first, and tested it before I even approached my executables. I think this is shown most clearly in image_functions, as the majority of the functions basically are just loops with one line calling the corresponding pixel functions.

This had some definite benefits. Because the pixel functions were so easy to test, most of my work was focused on the loops calling those functions, which all tended to be similar. Also, while not directly relevant to the actual code, since most other people started from the i/o side, when I got to that part (which was much harder than the pixel stuff) there was a wealth of answers on Piazza for my inevitable questions. This was particularly relevant when I was mixing row and column major; by the time I encountered it, the majority of the class had already encountered it and posted about it.

One holdup of my progress was my initial versions of crop and overlay, which in their first iteration was done in-place. This worked perfectly fine on part A of the project, but would have greatly complicated part B. Most of the final week was spent redoing crop and overlay and fixing the resulting bugs.


Looking Forward:

There are some possible performance improvements to be had- for example, returning pointers to structs instead of structs- but performance isn’t really an issue, and I avoid fixing things that aren’t problems. Looking forward to B, there might be some worries, but I’ll handle them as they come. I honestly don’t see anything too bad; the only potential for trouble will be in cropping the letter images out of the original, but the small size of the images should compensate for the repetition.