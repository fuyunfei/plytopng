#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define PNG_DEBUG 3
#include <png.h>

#ifndef PROPNG_H
#define PROPNG_H

png_bytep * read_png_file(char* file_name);
void write_png_file(char* file_name,png_bytep * row_pointers,int width, int height);
void process_file(png_bytep * row_pointers,int width ,int height);
void abort_(const char * s);
#endif

png_byte color_type;
png_byte bit_depth;
 int x,y;
int width, height;
png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
