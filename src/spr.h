#ifndef SPR_H
#define SPR_H
#include <stdlib.h>
#include <stdio.h>
int(*sprfunk[])(int i,int j, wrld)={moon,vonn};
int **spr(int metodaspr, wrld);
int moon(int i, int j, wrld);
int vonn(int i, int j, wrld);
int add(int i, int j, int k, int l,  wrld);
int rule1(int nlive, int whatmi);

#endif
