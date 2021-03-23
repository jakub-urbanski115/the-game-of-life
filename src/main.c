#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "spr.h"
#include "infiles.h"
#include "outfiles.h"
void help ()
{
	const char *guide =
"GUIDE:  	-g [liczba generacji są numerowane  0 - 'N' ]\n\n"
"		-e [nr generacji do zapisania mozna podac max 10]\n\n"
"		-f [scierzka folderu wyjsciowego]\n\n"
"		-c [0 marte 1 zywe krawedzie]\n\n"
"		-b [scierzka do pliku startowego z wielkoscia swiata i stanem poczatkowym w postaci: ]\n"
"				7 5 	 \n"
"				0 0 0 0 0\n"
"				0 0 1 0 0\n"
"				0 0 1 0 0\n"
"				0 1 1 0 0\n"
"				0 0 1 1 0\n"
"				0 0 1 0 0\n"
"				0 0 0 0 0\n\n"
"		-s [rodzaj metody sprawdzania sasiedztwa]\n"
"		0 - [Moore neighborhood]\n"
"		1 - [Von Neumann neighborhood]\n"
"		2 - [Na ksztalt litery X ]\n\n"
"		-r [rodzaj zasad]\n"
"		{(death by)(underpopulation)(overpopulation)	(creation by)(neighbours)}\n"
"		0 - [Standardowe]	{   <2	,   >3 	;	==3 	}\n"
"		1 - [rule2]		{   -	,   >2 	; 0 < alive < 3 }\n\n"
"		WYMAGANY JEST PLIK STARTOWY I FOLDER WYJSCIOWY!	\n\n";
	fprintf(stderr,"%s",guide);
	exit(EXIT_FAILURE);
}

int compere (const void *a,const void *b)	
{	
	return (  *(int*)a - *(int*)b );	
}
int main(int argc, char **argv)
{
//inicjalizacja zmiennych 
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
//kontrola ilosci argumentow min 2 domyslnie nalezy podac co najmniej -b -f
	if(argc<2)
		help();
//wczytywanie wartosci wywolania
	while((opt = getopt (argc, argv, "g:s:e:r:b:f:c:")) != -1 )
	{
		switch (opt)
		{
		case 'g' ://ilosc generacji
			lg = atoi(optarg);
		break;
		case 's' ://rodzaj metody sprawdzania 
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
		case 'r' ://zasady
			ruler = atoi(optarg);
		break;
		case 'b' ://plik startowy
			in = optarg; 
		break;
		case 'f'://folder wyjsciowy
			out = optarg;
		break;
		case 'c' ://status ramki wokol swiata
			c = atoi(optarg);	
		break;
		}
	}
	end[lend]=lg;
	qsort(end,11,sizeof(int), compere);//posortowanie wybranych gen do zapisu
	
	wrld *wld=NULL;
	wld = make(in);//allocation of the world
	
	if(wld == NULL)
		return 1;

	printPBM(wld,out,0);	
//sprawdzenie czy plik wejsciowy jest poprawny

//petla po generacjach
	for(int i=0; i < lg;i++)
	{
	int j= 10-lend;
	
	spr(metodaspr,ruler,c,wld);//glowna czesc ktora przetwarza swiat
		if(i==(end[j]-1))
		{
			printIt(wld,out,i+1);//quick save
			j++;
		}
				
		printPBM(wld,out,i+1);//generacja grafiki
	}
	freewrld(wld);//zwolnij swiat
	return 0;
}


