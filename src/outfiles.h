#ifndef _OUTFILES_H_
#define _OUTFILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infiles.h"
#include "gifenc.h"

void printIt(wrld * map, char* dir, int iter);
void printPBM(wrld * map, char* dir, int iter);
void gif_add(wrld * map, ge_GIF * gif);



#endif
