#include "spr.h"



int **spr(int metodaspr,  wrld )
{
int x = wrld->c;
int y = wrld->r;

int **tmp;//f. tworzaca world[x-1][y-1];
tmp=(int**)malloc((x-1)*(y-1)*sizeof(int));


for (int i=0; i<x; i++)
{
	for(int j=0; j < y; j++)
	{
		tmp[i][j]=(*sprfunk[metodaspr])(i,j,wrld);
	}
}
return tmp;
}

int moor(int i,int j, wrld)
{
int nlive=0;
for(int k=i-1; k < i + 2; k++)
{
	for(int l = j - 1; l < j + 2; j++)
	{
		nlive+=add(i,j,k,l,wrld);
	}
}
return rule1(nlive, wrld->world[i][j]);
}

int vonn(int i,int j, wrld)
{
int nlive=0;
	nlive+=add(i,j,k+1,l,wrld);
	nlive+=add(i,j,k-1,l,wrld);
	nlive+=add(i,j,k,l+1,wrld);
	nlive+=add(i,j,k,l-1,wrld);
return rule1(nlive, wrld->world[i][j]);
}

int add(int i, int j, int k, int l, wrld)
{
int n=0;
	if(k != i && l != j && k >= 0 && k < wrld->c && l >= 0 && l < world->r )
	{
		if(world[k][l]==1)
		n=1;
	}
return n;
}
