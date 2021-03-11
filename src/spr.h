#ifndef SPR_H
#define SPR_H
#include "infiles.h"
#include <stdlib.h>
#include <stdio.h>

int rule1 (int nlive, int whatmi);
int moon (int ruler, int i, int j, wrld * wld);
int vonn (int ruler, int i, int j, wrld * wld);
int (*sprfunk[2])(int , int ,int , wrld *);
void spr (int metodaspr,int rules, wrld * wld);
int add (int i, int j, int k, int l, wrld * wld);
int (*rules[1])(int , int );

#endif
