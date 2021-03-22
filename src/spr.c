#include "spr.h"

int (*sprfunk[])(int, int, int, int, wrld*)={moon,vonn,naX} ;
int (*rules[])(int,int)={rule1,rule2} ;
int (*addSS[])(int, int, int, int, wrld*)={add, add2} ;
void spr(int metodaspr, int ruler, int cr, wrld * wld )
{
//sprfunk[0]=moon;
//sprfunk[1]=vonn;
//sprfunk[2]=naX;

//rules[0]=rule1;
//rules[1]=rule2;

//addSS[0]=add;
//addSS[1]=add2;

int c = wld->c;
int r = wld->r;

wrld * new = copywrld(wld);//kopiowanie struct world

for (int i=0; i<r; i++)
{
	for(int j=0; j < c; j++)
	{
		wld->world[i][j]=(*sprfunk[metodaspr])(ruler,cr,i,j,new);//wybor funkicji z metoda sprawdzania
	}
}
freewrld(new);//zwalnianie pamieci
}
int naX(int ruler, int cr, int i, int j, wrld *wld) 
{
int nlive = 0;
	nlive += (*addSS[cr])(i,j,i+1,j+1,wld);
	nlive += (*addSS[cr])(i,j,i+1,j-1,wld);
	nlive += (*addSS[cr])(i,j,i-1,j+1,wld);
	nlive += (*addSS[cr])(i,j,i-1,j-1,wld);
return (*rules[ruler])(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
}

int moon(int ruler, int cr, int i, int j, wrld *wld) 
{
int nlive=0;
for(int l=i-1; l < i + 2; l++)
{
	for(int k = j - 1; k < j + 2; k++)
	{
		nlive += (*addSS[cr])(i,j,l,k,wld);//funkcja zawierajaca if-y
	}
}
return (*rules[ruler])(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
}						// i stan obecnej komorki swiata 

int vonn(int ruler,int cr, int i, int j, wrld * wld)
{
int nlive=0;
	nlive += (*addSS[cr])(i,j,i+1,j,wld);
	nlive += (*addSS[cr])(i,j,i-1,j,wld);
	nlive += (*addSS[cr])(i,j,i,j+1,wld);
	nlive += (*addSS[cr])(i,j,i,j-1,wld);
return (*rules[ruler])(nlive, wld->world[i][j]);//wybor zasad przekazuje liczbe zywych sasiadow
}

int add(int i, int j, int l, int k, wrld * wld)
{
int n=0;
	if(k == j && l == i)
	return 0;
	else{
		if(k >= 0 && k < wld->c && l >= 0 && l < wld->r )//zachowanie na krawedzi 
		{
			if(wld->world[l][k]==1)
			n=1;
		}
	}
return n;
}
int add2(int i, int j, int l, int k, wrld * wld)
{
int n = 0;
	if(k == j && l == i)
	return 0;
	else{
		if(k >= 0 && k < wld->c && l >= 0 && l < wld->r )//zachowanie na krawedzi 
		{
			if(wld->world[l][k]==1)
			n=1;
		}
	}
	if(k < 0 || k > (wld->c-1) || l < 0 || l > (wld->r-1) )//zachowanie na krawedzi 
		n=1;
return n;
}

