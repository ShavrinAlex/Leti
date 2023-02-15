#include <stdio.h>
#include <stdlib.h>
#include "getopt.h"
#include "structs.h"

int case_stroke_width(int argc, char *argv[], char *optarg, Configs *config, White *white){
        //flag passing check
        if (config->draw_white_area){

                //error checking
                if (!is_number(optarg)){
                        printf("\x1b[31mFlag {--strokewidth} takes arguments of type int\x1b[0m\n");
                        return -1;
                }

                white->stroke_width = atoi(optarg);
                return 0;
        } else{
                printf("\x1b[31mWhite area flag {-w}/{--white} not specified!\x1b[0m\n");
                return -1;
        }
}


int case_stroke_color(int argc, char *argv[], int *optind, Configs *config, White *white){
	//flag passing check
	if (config->draw_white_area){
		int args[3];	//temporary array of arguments
		int count = read_args(argc, argv, optind, 3, args);	//number of arguments read

		//error checking
		if (count == -1){
			printf("\x1b[31mFlag {--strokergb} takes arguments of type int\x1b[0m\n");
			return -1;
		}

		//checking if all arguments are passed
		if (count == 3){

			if (!is_rgb_numbers(args)){
				return -1;
			}

			white->stroke_color = (Rgb){args[2], args[1], args[0]};
			return 0;
		} else{
			printf("\x1b[31mFlag {--strokergb} taken 3 argument, but was given less argument\x1b[0m\n");
			return -1;
		}
	} else{
		printf("\x1b[31mWhite area flag {-w}/{--white} not specified!\x1b[0m\n");
		return -1;
	}
}
