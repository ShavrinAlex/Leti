CC = gcc

all: main.o getopt.o getopt_files.o bmp_info.o getopt_copy.o getopt_hexagon.o getopt_frame.o getopt_switch_color.o copy_area.o switch_color.o file_processing.o draw_hexagon.o draw_common_func.o draw_frame_serp.o draw_frame_koch.o draw_frame_minc.o draw_frame.o white_area.o getopt_white_area.o frame_out.o contrast.o glue.o collage.o square.o decrease.o stretch.o
	$(CC) -g -Wall main.o getopt.o getopt_files.o bmp_info.o getopt_copy.o getopt_hexagon.o getopt_frame.o getopt_switch_color.o copy_area.o switch_color.o file_processing.o draw_hexagon.o draw_common_func.o draw_frame_serp.o draw_frame_koch.o draw_frame_minc.o draw_frame.o white_area.o getopt_white_area.o frame_out.o contrast.o glue.o collage.o square.o decrease.o stretch.o -o main -lm

main.o: main.c structs.h getopt.h getopt_files.h bmp_info.h getopt_copy.h getopt_hexagon.h getopt_frame.h getopt_switch_color.h copy_area.h switch_color.h
	$(CC) -c main.c

glue.o: glue.c structs.h
	$(CC) -c glue.c

increase.o: increase.c structs.h
	$(CC) -c decrease.c

stretch.o: stretch.c structs.h draw_common_func.h
	$(CC) -c stretch.c

square.o: square.c structs.h
	$(CC) -c square.c

collage.o: collage.c structs.h
	$(CC) -c collage.c

frame_out.o: frame_out.c structs.h
	$(CC) -c frame_out.c

contrast.o: contrast.c structs.h
	$(CC) -c contrast.c

getopt_hexagon.o: getopt_hexagon.c getopt.h structs.h
	$(CC) -c getopt_hexagon.c

getopt_switch_color.o: getopt_switch_color.c getopt.h structs.h
	$(CC) -c getopt_switch_color.c

geopt_copy.o: getopt_copy.c getopt.h structs.h
	$(CC) -c getopt_copy.c

getopt_frame.o: getopt_frame.c getopt.h structs.h
	$(CC) -c getopt_frame.c

getopt_files.o: getopt_files.c getopt.h structs.h
	$(CC) -c getopt_files.c

bmp_info.o: bmp_info.c structs.h
	$(CC) -c bmp_info.c

file_processing.o: file_processing.c structs.h
	$(CC) -c file_processing.c

copy_area.o: copy_area.c structs.h getopt.h
	$(CC) -c copy_area.c

switch_color.o: switch_color.c draw_common_func.h structs.h
	$(CC) -c switch_color.c

draw_hexagon.o: draw_hexagon.c draw_common_func.h structs.h getopt.h
	$(CC) -c draw_hexagon.c

draw_frame.o: draw_frame.c draw_common_func.h draw_frame_serp.h structs.h getopt.h
	$(CC) -c draw_frame.c

draw_frame_serp.o: draw_frame_serp.c draw_common_func.h structs.h 
	$(CC) -c draw_frame_serp.c

draw_frame_koch.o: draw_frame_koch.c draw_common_func.h structs.h
	$(CC) -c draw_frame_koch.c

draw_frame_minc.o: draw_frame_minc.c structs.h
	$(CC) -c draw_frame_minc.c

white_area.o: white_area.c structs.h draw_common_func.h
	$(CC) -c white_area.c

draw_common_func.o: draw_common_func.c structs.h
	$(CC) -c draw_common_func.c

getopt.o: getopt.c structs.h
	$(CC) -c getopt.c

clean:
	rm -r *.o
