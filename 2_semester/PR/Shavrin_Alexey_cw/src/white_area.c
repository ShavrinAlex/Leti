#include <stdio.h>
#include "structs.h"
#include "draw_common_func.h"

void draw_stroke(Rgb **arr, File *file, Rgb *color_stroke, Rgb *color_area,  int i, int j, int n){
	if (n !=0){
		if (i-1 > 0 && !is_check_color(&arr[i-1][j], color_area)){
			set_pixel(&arr[i-1][j], color_stroke);
			draw_stroke(arr, file, color_stroke, color_area, i-1, j, n-1);
		}
		if (j < file->H && !is_check_color(&arr[i+1][j], color_area)){
			set_pixel(&arr[i+1][j], color_stroke);
			draw_stroke(arr, file, color_stroke, color_area, i+1, j, n-1);
		}
		if (j-1 > 0 && !is_check_color(&arr[i][j-1], color_area)){
			set_pixel(&arr[i][j-1], color_stroke);
			draw_stroke(arr, file, color_stroke, color_area, i, j-1, n-1);
		}
		if (j+1 < file->W && !is_check_color(&arr[i][j+1], color_area)){
			set_pixel(&arr[i][j+1], color_stroke);
			draw_stroke(arr, file, color_stroke, color_area, i, j+1, n-1);
		}
	}
}


void CircleWhiteArea(Rgb **arr, File *file, Rgb *color, int n){
	Rgb white = {255, 255, 255};
	for (int i = 0; i < file -> H; i++){
		for (int j = 0; j < file -> W; j++){
			if (is_check_color(&arr[i][j], &white)){
				draw_stroke(arr, file, color, &white, i, j, n);
			}
		}
	}
}
