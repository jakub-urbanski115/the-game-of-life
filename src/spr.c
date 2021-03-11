#include "spr.h"


void spr(int metodaspr,wrld * wld )
{
int x = wld->c;
int y = wld->r;

wrld * new = copywrld(wld);

/*int **tmp;//f. tworzaca world[x-1][y-1];
tmp=(int**)malloc(x*y*sizeof(int));
*/

for (int i=0; i<x; i++)
{
	for(int j=0; j < y; j++)
	{
		wld->world[i][j]=(*sprfunk[metodaspr])(i,j,new);
	}
}
}

int moor(int i,int j, wrld *wld) 
{
int nlive=0;
for(int k=i-1; k < i + 2; k++)
{
	for(int l = j - 1; l < j + 2; j++)
	{
		nlive+=add(i,j,k,l,wld);
	}
}
return (*rules[0])(nlive, wld->world[i][j]);
}

int vonn(int i,int j, wrld * wld)
{
int nlive=0;
	nlive+=add(i,j,i+1,j,wld);
	nlive+=add(i,j,i-1,j,wld);
	nlive+=add(i,j,i,j+1,wld);
	nlive+=add(i,j,i,j-1,wld);
return (*rules[0])(nlive, wld->world[i][j]);
}

int add(int i, int j, int k, int l, wrld * wld)
{
int n=0;
	if(k != i && l != j && k >= 0 && k < wld->c && l >= 0 && l < wld->r )
	{
		if(wld->world[k][l]==1)
		n=1;
	}
return n;
}
