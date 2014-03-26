/*
 * save_load.c
 *
 *  Created on: Mar 25, 2014
 *      Author: dhia
 */

#include <stdlib.h>
#include <stdio.h>

#include "interface.h"


//This should work properly
//TODO : Test this function
Boolean load(Arena* a, Arena* solution){
	Boolean exit_status = True;
	int i=0, j=0;
	Vector size ;
	FILE* fin  = NULL;

	fin = fopen("game","r"); //Opening file

	//getting game arena's dimension
	fscanf(fin, "%d %d", &size.c,&size.l);

	//creating the imported arenas with the correct size
	*a = create(size);
	*solution = create(size);

	if(NULL!=fin){	//file opened correctly
		//reading fields' properties
		for ( i=0 ; i<sqr(a->size->l) ; i++){
			for ( j=0 ; j<sqr(a->size->c) ; j++){
				fscanf(fin, "%d", a->Arena[i][j].val);
			}
		}
		for ( i=0 ; i<sqr(solution->size->l) ; i++){
			for ( j=0 ; j<sqr(solution->size->c) ; j++){
				fscanf(fin, "%d", solution->Arena[i][j].val);
			}
		}
	}
	else {
		fprintf(stderr,"Can't open file in read mode");
		exit_status = False;
	}

	if(fclose(fin)!=0) exit_status = False;
	return exit_status;
}

//this should work TODO : test it!
Boolean save(Arena a, Arena solution){
	Boolean exit_status = True;
	FILE* fout = NULL;
	fout = fopen("game","w"); //Opening file for writing
	int i = 0, j = 0;

	if(NULL!=fout){
		fprintf(fout,"%d %d\n", a.size.c , a.size.l);	//saving arena's dimensions
		//writing each fields property on a new line
		for(i=0; i<sqr(a.size.l); i++){			// each line of the actual arena
			for (j=0 ;j<sqr(a.size.c) ; j++){ 	//each field
				fprintf(fout, "%d ",*(a.Arena[i][j].val));// saving the value
			}
			fprintf(fout,"\n");
		}
		for(i=0; i<sqr(a.size.l); i++){			// each line of the actual arena
			for (j=0 ;j<sqr(a.size.c) ; j++){ 	//each field
				fprintf(fout, "%d ",*(solution.Arena[i][j].val));// saving the value
			}
			fprintf(fout,"\n");
		}
	}
	else{
		fprintf(stderr,"Can't open file in write mode");
		exit_status=False;
	}

	if(fclose(fout)!=0)	exit_status = False ;
	return exit_status;
}