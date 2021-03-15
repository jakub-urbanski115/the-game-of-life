#include "spr.h"

int (*sprfunk[])(int, int, int, wrld*)={moon,vonn} ;

void spr(int metodaspr,int ruler, wrld * wld )
{
//sprfunk[0]=moon;
//sprfunk[1]=vonn;

rules[0]=rule1;

int c = wld->c;
int r = wld->r;

wrld * new = copywrld(wld);//kopiowanie struct world

for (int i=0; i<r; i++)
{
	for(int j=0; j < c; j++)
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
for(int l=i-1; l < i + 2; l++)
{
	for(int k = j - 1; k < j + 2; k++)
	{
		nlive+=add(i,j,l,k,wld);//funkcja zawierajaca if-y
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

int add(int i, int j, int l, int k, wrld * wld)
{
int n=0;
	if(k != j && l != i && k >= 0 && k < wld->c && l >= 0 && l < wld->r )//zachowanie na krawedzi 
	{
		if(wld->world[l][k]==1)
		n=1;
	}
return n;
}
