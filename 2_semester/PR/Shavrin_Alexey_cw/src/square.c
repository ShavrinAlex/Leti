#include <stdio.h>
#include "structs.h"
#include "draw_common_func.h"

int mx(int f, int s){
	if (f > s){return f;}
	return s;
}

int mn(int f, int s){
	if (f > s){return s;}
	return f;
}


void DrawSquare(Rgb **arr, File *file, int r){
	Rgb red = {49, 32, 213};
	Rgb blue = {255, 0, 0};
	int x, y;
	for (int i = 0; i < file->H; i++){
		for (int j = 0; j < file->W; j++){
			if (is_check_color(&arr[i][j], &red)){
				x = j - r;
				if (x > 0){
					for (y = mx(0, i-r); y < mn(file->H, i+r); y++){
						set_pixel(&arr[y][x], &blue);
					}
				}
				x = j + r;
				if (x < file->W){
					for (y = mx(0, i-r); y < mn(file->H, i+r); y++){
						set_pixel(&arr[y][x], &blue);
					}
				}
				y = i - r;
				if (y > 0){
					for (x = mx(0, j-r); x < mn(file->W, j+r); x++){
						set_pixel(&arr[y][x], &blue);
					}
				}
				y = i + r;
				if (y < file->H){
					for (x = mx(0, j-r); x < mn(file->W, j+r); x++){
						set_pixel(&arr[y][x], &blue);
					}
				}

			}
		}
	}

}
