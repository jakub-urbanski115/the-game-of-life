#include "infliles.h"

wrld * make(char* filename){
	wrld *new_wrld = malloc (sizeof *new_wrld);
	if(check(filename) == 0){
		FILE *fin = fopen(filename,"w");
		fscanf(fin, "%d %d", new_wrld->&r, &new_wrld->&c);
		
		new_wrld->world = malloc(new_wrld->r * sizeof(int));

		for(int i = 0; i < r; i++)
			new_wrld->world[i] = malloc(new_wrld->c * sizeof(int));

		for(int i = 0; i < new_wrld->r; i++)
			for(int j = 0; j < new_wrld->j; j++)
				fscanf(fin, "%d", new_wrld->world[i][j]);

		return new_wrld;
	}

	else{
	       	new_wrld = NULL; // w mainie, jesli new_wrld == NULL to koniec programu :(	
		return new_wrld;  
	}
}


int check(char* filename){
	int r,c,x;
	int sum = 0;

	FILE * fin = fopen(filename,"r");

	if(fin != NULL){

		fscanf(fin, "%d %d", &r , &c);

		while(fscanf(fin, "%d", &x) == 1){
			if(x != 0 && x != 1){
				fprintf(stderr,"Niewlasciwe dane w pliku (powinny byc zera i jedynki!)\n");
				return 1;
			}
			suma++;
		}
		if(suma != r*c){
			fprintf(stderr,"Liczba kolumn i wierszy nie zgadza sie z iloscia danych\n");
			return 1;
		}
	}
	else{
		fprintf(stderr,"Nie mozna odczytac pliku o podanej nazwie\n");
		return 1;
	}

	return 0;
}


wrld * copywrld(wrld * w){
	wrld * new = malloc(sizeof(new));
	new->r = w->r;
	new->c = w->c;

	new->world = malloc(new->r * sizeof(int));

	for(int i = 0; i < r; i++)
		new->world[i] = malloc(new->c * sizeof(int));

	for(int i = 0; i < new->r; i++)
		for(int j = 0; j < new->j; j++)
			new->world[i][j] = w->world[i][j];

	return new;

}


void freewrld(wrld * w){

	free(w->world);
	free(w);	
}
