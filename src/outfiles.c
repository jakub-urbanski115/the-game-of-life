#include "outfiles.h"

void printIt(wrld * map, char* dir, int iter){ // zapis konkretnej iteracji do pliku w podanym folderze "dir"
	char *file = malloc(strlen(dir) + strlen("zapis_iteracji_.txt") + 3);
	file = strcpy(file, dir);
	file = strcat(file, "/zapis_iteracji_");
	int x = iter;
	int d = 0;
	while( x < 0){ // sprawdzenie ile cyfr ma iteracja, zeby zaalokowac pamiec na char c
		x /= 10;
		d++;
	}
	char *c = malloc(d);
	sprintf(c,"%d",iter);
	file = strcat(file, c);
	file = strcat(file, ".txt");

	FILE * out = fopen(file,"w");

	fprintf(out,"%d %d\n",map->r, map->c);
	for(int i = 0; i < map->r; i++){
		for(int j = 0; j < map->c; j++)
            fprintf(out,"%d ", map->world[i][j]);
        fprintf(out,"\n");
	}
	fclose(out);
	free(c);
	free(file);
}

