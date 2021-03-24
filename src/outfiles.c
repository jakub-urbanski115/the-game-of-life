#include "outfiles.h"
#include <unistd.h>
#include <limits.h>

void printIt(wrld * map, char* dir, int iter){ // zapis konkretnej iteracji do pliku w podanym folderze "dir"
	if(dir == NULL){
		char cdir[PATH_MAX];
		getcwd(cdir, sizeof(cdir));
		dir = cdir;
	}

	char *file = malloc((strlen(dir) + strlen("zapis_iteracji_.txt") + 4)*sizeof(char));
	strcpy(file, dir);
	strcat(file, "/zapis_iteracji_");
	int x = iter;
	int d = 0;
	while( x < 0){ // sprawdzenie ile cyfr ma iteracja, zeby zaalokowac pamiec na char c
		x /= 10;
		d++;
	}
	char *c = malloc((d+3)*sizeof(char));
	sprintf(c,"%d",iter);
	strcat(file, c);
	strcat(file, ".txt");

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


void printPBM(wrld * map, char* dir, int iter){ 
	if(dir == NULL){
		char cdir[PATH_MAX];
		getcwd(cdir, sizeof(cdir));
		dir = cdir;
	}

	char *file = malloc(strlen(dir) + strlen("pic_.pbm") + 4);
	strcpy(file, dir);
	strcat(file, "/pic_");
	int x = iter;
	int d = 0;
	while( x < 0){ 
		x /= 10;
		d++;
	}
	char *c = malloc((d+3)*sizeof(char));
	sprintf(c,"%d",iter);
	strcat(file, c);
	strcat(file, ".pbm");

	FILE * out = fopen(file,"w");

	fprintf(out,"P1\n");
	fprintf(out,"%d %d\n",map->c, map->r);
	for(int i = 0; i < map->r; i++){
		for(int j = 0; j < map->c; j++)
            fprintf(out,"%d ", map->world[i][j]);
        fprintf(out,"\n");
	}
	fclose(out);
	free(c);
	free(file);
}


void gif_add(wrld * map, ge_GIF * gif){
	for(int i = 0; i < map->r; i++)
		for(int j = 0; j < map->c; j++)
			gif->frame[map->c*i + j] = map->world[i][j];
	ge_add_frame(gif,20);
}
