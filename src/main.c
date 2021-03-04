#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "spr.h"

int compere (const void *a,const void *b)	
{
	return (  *(int*)a - *(int*)b );	
}
int main(int argc, char **argv)
{
	int opt;
	int lg=1;
	int metodaspr = 0;
	int lend=0;
	int *end;
	char *in = NULL;
	char *out = NULL;

	end = malloc(10*sizeof(int));
	while((opt = getopt (argc, argv, "g:s:e:f:b")) != -1 )
	{
		switch (opt)
		{
		case 'g':
			lg = atoi(optarg);
		break;
		case 's' :
			metodaspr = atoi(optarg);
		break;
		case 'e' :
			end[lend] = atoi(optarg);
			lend++;
			//czy dodawac realloc?
			//kolejne konce musza rownierz zaczynac sie od -e
		break;
		case 'b' :
			in = optarg; 
		break;
		case 'f':
			out = optarg;
		break;
		}
	}
	lend= sizeof(end);
	qsort(end,lend,sizeof(int), compere);

	//world = dane(FILEIN)
	if(metodaspr == 1)
	{
		int(*sprfunk)()	= moon;
	}
	else
	{
		int(*sprfunk)()	= vonn;	
	}

	for(int i=0; i < lg;i++)
	{
	int j= 0;
		sprfunk();
		if(i==end[j])
		{
			//savestan
			j++;
		}
		//grafika
	}

	return 0;
}


