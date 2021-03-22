#ifndef SPR_H
#define SPR_H
#include "infiles.h"
#include <stdlib.h>
#include <stdio.h>

int rule1 (int nlive, int whatmi);
int rule2 (int nlive, int whatmi);
int naX (int ruler, int cr, int i, int j, wrld * wld);
int moon (int ruler, int cr, int i, int j, wrld * wld);
int vonn (int ruler, int cr, int i, int j, wrld * wld);
int (*sprfunk[3])(int, int, int ,int , wrld *);
void spr (int metodaspr,int rules, int cr, wrld * wld);
int add (int i, int j, int l, int k, wrld * wld);
int add2 (int i, int j, int l, int k, wrld * wld);
int (*rules[2])(int, int );
int (*addSS[2])(int, int, int, int, wrld *);

#endif
