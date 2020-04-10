#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

#include <GL/gl.h>	
#include <GL/glut.h>
#include <GL/glu.h>	
#include <unistd.h>     
#include <math.h>
#include <string.h>

typedef unsigned long ulong;

typedef struct Image Image;
struct Image {
    ulong sizeX;
    ulong sizeY;
    GLubyte *data;
};

typedef unsigned short utab [3][3][3];

int ImageLoad_PPM(char *filename, Image *image);
void imagesave_PPM(char *filename, Image *image);
