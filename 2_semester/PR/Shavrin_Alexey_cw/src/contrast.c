#include <stdio.h>
#include "structs.h"


void Contrast(Rgb **arr, File *file, int val){
	double contrast = (100.0 + val) / 100.0;
	contrast = contrast * contrast;
	for (int i = 0; i < file->H; i++){
		for (int j = 0; j < file->W; j++){
			double r = arr[i][j].r;
			double g = arr[i][j].g;
			double b = arr[i][j].b;
	
			//red
			r /= 255.0;
			r -= 0.5;
			r *= contrast;
			r += 0.5;
			r *= 255.0;
			if (r < 0){r = 0;}
			if (r > 255){r = 255;}
			
			//green
			g /= 255.0;
			g -= 0.5;
			g *= contrast;
			g += 0.5;
			g *= 255.0;
			if (g < 0){g = 0;}
			if (g > 255){g = 255;}

			//blue
			b /= 255.0;
			b -= 0.5;
			b *= contrast;
			b += 0.5;
			b *= 255.0;
			if (b < 0){b = 0;}
			if (b > 255){b = 255;}
			arr[i][j] = (Rgb){b, g, r};
		}
	}
}
