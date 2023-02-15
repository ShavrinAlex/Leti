#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include "draw_common_func.h"

int min(int f, int s){
	if (f > s){return s;}
	return f;
}


int Glue(File *file1, File *file2){
	printf("1- %d %d\n2- %d %d\n", file1->H, file1->W, file2->H, file2->W);
	int new_w = min(file1->W, file2->W);
	int new_h = 2*min(file1->H, file2->H);
	printf("%d %d\n", new_h, new_w);

	//pictures reading
	Rgb **new_arr = malloc(new_h*sizeof(Rgb*));

	//error checking
	if (new_arr == NULL){
		printf("\x1b[31mH Unable to allocate memmory for image\x1b[0m\n");
		return -1;
	}

	int y = 0;
	for(int i=0; i<new_h; i++){
		new_arr[i] = malloc(new_w * sizeof(Rgb) + (new_w*3)%4);

		//error checking
		if (new_arr[i] == NULL){
			printf("\x1b[31mW Unable to allocate memmory for image\x1b[0m\n");
			return -1;
		}
		for (int j = 0; j < new_w; j++){
			if (i % 2 == 0){
				set_pixel(&new_arr[i][j], &file1->arr[y][j]);
			} else{
				set_pixel(&new_arr[i][j], &file2->arr[y][j]);
			}
		}
		if (i % 2 != 0){y++;}
	}
	file1->arr = new_arr;
	file1->bmih->width = new_w;
	file1->bmih->height = new_h;
	file1->H = new_h;
	file1->W = new_w;
}
