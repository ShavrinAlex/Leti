#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "draw_common_func.h"


Rgb *new_color(Rgb **arr, int i, int j, File *file, Rgb *color){
	unsigned int r = arr[i][j].r;
	unsigned int g = arr[i][j].g;
	unsigned int b = arr[i][j].b;
	if (i + 1 < file->H){
		r+=arr[i+1][j].r;
		g+=arr[i+1][j].g;
		b+=arr[i+1][j].b;
	}
	if (i - 1 > 0){
		r+=arr[i-1][j].r;
		g+=arr[i-1][j].g;
		b+=arr[i-1][j].b;
	}
	if (j - 1 > 0){
		r+=arr[i][j-1].r;
		g+=arr[i][j-1].g;
		b+=arr[i][j-1].b;
	}
	if (j + 1 < file->W){
		r+=arr[i][j+1].r;
		g+=arr[i][j+1].g;
		b+=arr[i][j+1].b;
	}
	r /= 4;
	g /= 4;
	b /= 4;
	if (r > 255){r = 255;}
	if (g > 255){g = 255;}
	if (b > 255){b = 255;}
	color->b = b;
       	color->g = g;
       	color->r = r;
	return color;
}


int Decrease(Rgb **arr, File *file){
	int new_w = file->W/2;
	int new_h = file->H/2;

	Rgb **new_arr = malloc(new_h * sizeof(Rgb*));

	if (new_arr == NULL){
		printf("\x1b[31mh Unable to allocate memmory for copy_arr\x1b[0m\n");
		return -1;
	}

	for(int i = 0; i < new_h; i++){
		new_arr[i] = malloc(new_w * sizeof(Rgb));
		if (new_arr[i] == NULL){
			printf("\x1b[31mw Unable to allocate memmory for copy_arr\x1b[0m\n");
			return -1;
		}
	}

	int y = 0;
	Rgb color;
	for (int i = 0; i < new_h; i++){
		int x = 0;
		for (int j = 0; j < new_w; j++){
			if (x < file->W && y < file->H){
				set_pixel(&new_arr[i][j], new_color(arr, y, x, file, &color));
				x += 2;
			}
		}
		y += 2;
	}

	file->arr = new_arr;
	file->bmih->width = new_w;
	file->bmih->height = new_h;
	file->W = new_w;
	file->H = new_h;
}
