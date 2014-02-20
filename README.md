229C
====

Project 1 for ISU's Comp Sci 229


Design Decisions:

I tried to approach my executables from a pixel up perspective. I wrote my pixel_functions file first, and tested it before I even approached my executables. I think this is shown most clearly in image_functions, as the majority of the functions basically are just loops with one line calling the corresponding pixel functions.

This had some definite benefits. Because the pixel functions were so easy to test, most of my work was focused on the loops calling those functions, which all tended to be similar. Also, while not directly relevant to the actual code, since most other people started from the i/o side, when I got to that part (which was much harder than the pixel stuff) there was a wealth of answers on Piazza for my inevitable questions. This was particularly relevant when I was mixing row and column major; by the time I encountered it, the majority of the class had already encountered it and posted about it.

One holdup of my progress was my initial versions of crop and overlay, which in their first iteration was done in-place. This worked perfectly fine on part A of the project, but would have greatly complicated part B. Most of the final week was spent redoing crop and overlay and fixing the resulting bugs.


Looking Forward:

There are some possible performance improvements to be had- for example, returning pointers to structs instead of structs- but performance isn’t really an issue, and I avoid fixing things that aren’t problems. Looking forward to B, there might be some worries, but I’ll handle them as they come. I honestly don’t see anything too bad; the only potential for trouble will be in cropping the letter images out of the original, but the small size of the images should compensate for the repetition.