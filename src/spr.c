#include "spr.h"


void spr(int metodaspr,int ruler, wrld * wld )
{
sprfunk[0]=moon;
sprfunk[1]=vonn;

rules[0]=rule1;

int x = wld->c;
int y = wld->r;

wrld * new = copywrld(wld);//kopiowanie struct world

for (int i=0; i<x; i++)
{
	for(int j=0; j < y; j++)
	{
		wld->world[i][j]=(*sprfunk[metodaspr])(ruler,i,j,new);//wybor funkicji z metoda sprawdzania
	}
}
freewrld(new);//zwalnianie pamieci
}

int moon(int ruler, int i,int j, wrld *wld) 
{
//int x=0;
int nlive=0;
for(int k=i-1; k < i + 2; k++)
{
	for(int l = j - 1; l < j + 2; j++)
	{
		nlive+=add(i,j,k,l,wld);//funkcja zawierajaca if-y
	}
}
return (*rules[ruler])(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
//x = rule1(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
}						// i stan obecnej komorki swiata 

int vonn(int ruler, int i,int j, wrld * wld)
{
int nlive=0;
	nlive+=add(i,j,i+1,j,wld);
	nlive+=add(i,j,i-1,j,wld);
	nlive+=add(i,j,i,j+1,wld);
	nlive+=add(i,j,i,j-1,wld);
return (*rules[ruler])(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
}

int add(int i, int j, int k, int l, wrld * wld)
{
int n=0;
	if(k != i && l != j && k >= 0 && k < wld->c && l >= 0 && l < wld->r )//zachowanie na krawedzi 
	{
		if(wld->world[k][l]==1)
		n=1;
	}
return n;
}
