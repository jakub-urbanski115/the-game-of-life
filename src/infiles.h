#ifndef _INFILES_H_
#define _INFILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int r;
	int c;
	int **world;
} wrld;

wrld * make(char* filename);
int check(char* filename);
wrld * copywrld(wrld * w);
void freewrld(wrld * w);

#endif

