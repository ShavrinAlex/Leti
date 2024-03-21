#pragma once

int read_input_file(Configs *config, File *file, BitmapFileHeader *bmfh, BitmapInfoHeader *bmih, int n);
int create_output_file(Configs *config, File *file);
