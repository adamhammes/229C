/*
	Defines the structure to hold the image.
*/


typedef struct image_s {
	unsigned int width;
	unsigned int heigth;

	Pixel** pixels; // will hold the pixels of the image.
} Image;