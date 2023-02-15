#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


#define ROOT_DIRECTORY "./tmp_var_4"
#define OUTPUT_FILE_NAME "result.txt"
#define BASE_SIZE 300

typedef struct Buffer{
	char *content;
	int size;
} Buffer;


int ExtendBuffer(Buffer *buffer){
	buffer->size += BASE_SIZE;
	char *tmp = realloc(buffer->content, buffer->size);
	if (tmp){
		buffer->content = tmp;
		return 0;
	}
	return -1;
}


int SearchingFile(Buffer *path, char *file_name){
	char *current_directory_name = path->content;
	DIR *current_directory = opendir(current_directory_name);
	if (!current_directory){return 0;}

	struct dirent *dp;
	while (dp = readdir(current_directory)){
		if (dp->d_type == DT_DIR && (!strcmp(dp->d_name, ".") || (!strcmp(dp->d_name, "..")))){
				continue;
		}

		if (dp->d_type == DT_REG && !strcmp(file_name, dp->d_name)){
			if (strlen(current_directory_name) + strlen(dp->d_name)+2 > path->size && ExtendBuffer(path) == -1){
				closedir(current_directory);
				return 0;
			}

			strcat(current_directory_name, "/");
			strcat(current_directory_name, dp->d_name);

			closedir(current_directory);
			return 1;
		}else{
			if (dp->d_type == DT_DIR){
				if (strlen(current_directory_name) + strlen(dp->d_name)+2 > path->size && ExtendBuffer(path) == -1){
					closedir(current_directory);
					return 0;
				}
			
				int dir_name_length = strlen(current_directory_name);

				strcat(current_directory_name, "/");
				strcat(current_directory_name, dp->d_name);

				int out = SearchingFile(path, file_name);
				if (out){
					closedir(current_directory);
					return 1;
				}

				current_directory_name[dir_name_length] = '\0';
			}	
		}
	}
	closedir(current_directory);
	return 0;
}

int main(){
	Buffer path;
	path.content = malloc(BASE_SIZE*sizeof(char));
	if (path.content == NULL){return -1;}

	char file_name[strlen("_.txt")+1];
	strcpy(file_name, "_.txt");

	FILE *file = fopen(OUTPUT_FILE_NAME, "w");
	if (file==NULL){return -1;}

	scanf("%c", &file_name[0]);
	while (file_name[0] != '\n'){
		strcpy(path.content, ROOT_DIRECTORY);
		if (SearchingFile(&path, file_name)){
			fprintf(file, "%s\n", path.content);
			scanf("%c", &file_name[0]);
		} else{
			free(path.content);
			fclose(file);
			return -1;
		}
	}

	free(path.content);
	fclose(file);
	return 0;
}
