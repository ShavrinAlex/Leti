#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "draw_common_func.h"


int max(int f, int s){
	if (f > s){return f;}
	return s;
}

int Collage(File *file1, File *file2){
	int new_w = file1->W + file2->W;
	int new_h = max(file1->H, file2->H);
	printf("%d %d\n", new_h, new_w);

	//pictures reading
	Rgb **new_arr = malloc(new_h*sizeof(Rgb*));

	//error checking
	if (new_arr == NULL){
		printf("\x1b[31mH Unable to allocate memmory for image\x1b[0m\n");
		return -1;
	}

	Rgb white = {255, 255, 255};
	for(int i=0; i<new_h; i++){
		new_arr[i] = malloc(new_w * sizeof(Rgb) + (new_w*3)%4);

		//error checking
		if (new_arr[i] == NULL){
			printf("\x1b[31mW Unable to allocate memmory for image\x1b[0m\n");
			return -1;
		}
		for (int j = 0; j < new_w; j++){
			if (j < file1->W){
				if (i >=  file1->H){
					set_pixel(&new_arr[i][j], &white);
				} else {
					set_pixel(&new_arr[i][j], &file1->arr[i][j]);
				}
			} else{
				if (i >=  file2->H){
					set_pixel(&new_arr[i][j], &white);
				} else {
					set_pixel(&new_arr[i][j], &file2->arr[i][j-file1->W]);
				}
			}
		//printf("%d %d\n", i, j);
		}
	}
	file1->arr = new_arr;
	file1->bmih->width = new_w;
	file1->bmih->height = new_h;
	file1->H = new_h;
	file1->W = new_w;
}
