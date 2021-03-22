#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "spr.h"
#include "infiles.h"
#include "outfiles.h"
void help ()
{
	char *guide =
"GUIDE: %s 	-g [liczba generacji]\n"
"		-s [rodzaj metody sprawdzania sasiedztwa]\n"
"		-e [nr generacji do zapisania mozna podac max 10]\n"
"		-r [rodzaj zasad]\n"	
"		-b [plik startowy z ...]\n"
"		-f [folder wyjsciowy]\n"
"		-c [0 marte 1 zywe krawedzie]\n"
"\n";
	fprintf(stderr,"%s",guide);
	exit(EXIT_FAILURE);
}

int compere (const void *a,const void *b)	
{	
	return (  *(int*)a - *(int*)b );	
}
int main(int argc, char **argv)
{
	int opt;
	int lg=2;
	int ruler = 0;
	int metodaspr = 0;
	int lend=0;
	int end[11]={0};
	char *in = NULL;
	char *out = NULL;
	int c = 0;
	int tmp=0;	
	if(argc<2)
		help();

	while((opt = getopt (argc, argv, "g:s:e:r:b:f:c:")) != -1 )
	{
		switch (opt)
		{
		case 'g' ://ilosc generacji
			lg = atoi(optarg);
		break;
		case 's' ://rodzaj metody sprawdzania czy sasiedzi sa zywi
			metodaspr = atoi(optarg);
		break;
		case 'e' ://ktore generacje zapisac
			tmp = atoi(optarg);
			if(tmp>0)
			{ 
				end[lend]=tmp;
				lend++;
			}else
			help();
		break;
		case 'r' :
			ruler = atoi(optarg);
		break;
		case 'b' ://plik startowy
			in = optarg; 
		break;
		case 'f'://folder wyjsciowy
			out = optarg;
		break;
		case 'c' :
			c = atoi(optarg);	
		break;
		}
	}
	end[lend]=lg;
	qsort(end,11,sizeof(int), compere);//posortowanie wybranych gen do zapisu
	
	wrld *wld=NULL;
	wld = make(in);//allocation of the world

	if(wld==NULL)
	return 1;

	for(int i=0; i < lg;i++)
	{
	int j= 10-lend;
	
	spr(metodaspr,ruler,c,wld);//glowna czesc ktora przetwarza swiat
		if(i==(end[j]-1))
		{
			printIt(wld,out,i);//savestan
			j++;
		}
				
		printPBM(wld,out,i);//grafika
	}
	freewrld(wld);
	return 0;
}


