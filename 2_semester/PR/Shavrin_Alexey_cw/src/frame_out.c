#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include "draw_common_func.h"
#include "draw_frame.h"
#include "copy_area.h"


int DrawFrameOut(Rgb **arr, File *file, Frame *frame){
	int new_h = 2*frame->width + file->H;
	int new_w = 2*frame->width + file->W;

	//pictures reading
	Rgb **new_arr = malloc(new_h*sizeof(Rgb*));
	
	//error checking
	if (new_arr == NULL){
		printf("\x1b[31mH Unable to allocate memmory for image\x1b[0m\n");
		return -1;
	}

	for(int i=0; i<new_h; i++){
		new_arr[i] = malloc(new_w * sizeof(Rgb) + (new_w*3)%4);

		//error checking
		if (new_arr[i] == NULL){
			printf("\x1b[31mW Unable to allocate memmory for image\x1b[0m\n");
			return -1;
		}
	}
	for (int i = 0; i < file->H; i++){	
		for (int j = 0; j < file->W; j++){
			new_arr[i+frame->width][j+frame->width] = arr[i][j];
		}
	}
	file->arr = new_arr;
	file->bmih->height = new_h;
        file->bmih->width  = new_w;
	file->W = new_w;
	file->H = new_h;	
	draw_bg_frame(frame, file->arr, file);
}
