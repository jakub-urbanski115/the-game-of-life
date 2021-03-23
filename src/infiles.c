#include "infiles.h"

wrld * make(char* filename){
	wrld *new_wrld = malloc (sizeof *new_wrld);
	if(check(filename) == 0){
		FILE *fin = fopen(filename,"r");
		fscanf(fin, "%d %d", &new_wrld->r, &new_wrld->c);
		
		new_wrld->world = (int **)malloc(new_wrld->r * sizeof(int*));

		for(int i = 0; i < new_wrld->r; i++)
			new_wrld->world[i] = (int *)malloc(new_wrld->c * sizeof(int));

		for(int i = 0; i < new_wrld->r; i++)
			for(int j = 0; j < new_wrld->c; j++)
				fscanf(fin, "%d", &new_wrld->world[i][j]);

		fclose(fin);
		return new_wrld;
	}

	else{
	        // w mainie, jesli new_wrld == NULL to koniec programu :(	
		free(new_wrld);
		return NULL;  
	}
}


int check(char* filename){
	int r=1;
	int c=1;
	int x;
	int suma = 0;

	FILE * fin = fopen(filename,"r");

	if(fin != NULL){

		fscanf(fin, "%d %d", &r , &c);

		while(fscanf(fin, "%d", &x) == 1){
			if(x != 0 && x != 1){
				fprintf(stderr,"Niewlasciwe dane w pliku (powinny byc zera i jedynki!)\n");
				fclose(fin);
				return 1;
			}
			suma++;
		}
		if(suma != r*c){
			fprintf(stderr,"Liczba kolumn i wierszy nie zgadza sie z iloscia danych\n");
			fclose(fin);
			return 1;
		}
	}
	else{
		fprintf(stderr,"Nie mozna odczytac pliku o podanej nazwie\n");
		return 1;
	}
	
	fclose(fin);
	return 0;
}


wrld * copywrld(wrld * w){
	wrld * new = malloc(sizeof *new);
	new->r = w->r;
	new->c = w->c;

	new->world = (int **)malloc(new->r * sizeof(int*));

	for(int i = 0; i < new->r; i++)
		new->world[i] = (int *)malloc(new->c * sizeof(int));

	for(int i = 0; i < new->r; i++)
		for(int j = 0; j < new->c; j++)
			new->world[i][j] = w->world[i][j];

	return new;

}


void freewrld(wrld * w){
	for(int i = 0; i < w->r; i++)
		free(w->world[i]);
	free(w->world);
	free(w);	
}
