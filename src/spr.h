#ifndef SPR_H
#define SPR_H
#include "infiles.h"
#include <stdlib.h>
#include <stdio.h>
int moon(int i, int j, wrld * wld);
int vonn(int i, int j, wrld * wld);
int(*sprfunk[])(int i,int j, wrld * wld)={moon,vonn};
void spr(int metodaspr, wrld * wld);
int add(int i, int j, int k, int l, wrld * wld);
int rule1(int nlive, int whatmi);

#endif
