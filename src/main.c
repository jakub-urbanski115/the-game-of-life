#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "spr.h"
#include "infiles.h"

void help ()
{
	char *guide =
"GUIDE: %s 	-g [liczba generacji]\n"
"		-s [rodzaj metody sprawdzania sasiedztwa]\n"
"		-e [nr generacji do zapisania mozna podac wiele kazdy z prefixem (-e)]\n"
"		-r [rodzaj zasad]\n"	
"		-b [plik startowy z ...]\n"
"		-f [folder wyjsciowy]\n"
"\n";
	fprintf(stderr,guide);
	exit(EXIT_FAILURE);
}

int compere (const void *a,const void *b)	
{
	return (  *(int*)a - *(int*)b );	
}
int main(int argc, char **argv)
{
	int opt;
	int lg=1;
	int ruler = 0;
	int metodaspr = 0;
	int lend=0;
	int *end;
	char *in = NULL;
	char *out = NULL;
	
	if(argc<2)
		help;

	end =(int*)malloc(10*sizeof(int));
	
	while((opt = getopt (argc, argv, "g:s:e:r:b:f")) != -1 )
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
			end[lend] = atoi(optarg);
			lend++;
			//czy dodawac realloc?
			//kolejne konce musza rownierz zaczynac sie od -e
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
		}
	}
	lend= sizeof(end);
	qsort(end,lend,sizeof(int), compere);//posortowanie wybranych gen do zapisu

	wrld *wld=NULL;
	wld = make(in);//allocation of the world
	
	for(int i=0; i < lg;i++)
	{
	int j= 0;
	spr(metodaspr,ruler,wld);//glowna czesc ktora przetwarza swiat
		if(i==end[j])
		{
			//savestan
			j++;
		}
		//grafika
	}
	freewrld(wld);
	return 0;
}


