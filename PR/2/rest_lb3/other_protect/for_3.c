#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#define FILE_TYPE ".txt"
#define ROOT "./test_for_3"


void Recursion(char *Path, char *file_type){
	DIR *cur_dir = opendir(Path);
	if (cur_dir == NULL){return;}

	struct dirent *dt;
	while(dt = readdir(cur_dir)){
		if (dt->d_type == DT_DIR && (!strcmp(dt->d_name, ".") || !strcmp(dt->d_name, ".."))){
				continue;
		}

		int len = strlen(Path);
		strcat(Path, "/");
		strcat(Path, dt->d_name);
		if (dt->d_type == DT_REG && strstr(dt->d_name, file_type)){
			remove(Path);
			printf("file %s remove\n", dt->d_name);
		} else{
			if (dt->d_type == DT_DIR){
				Recursion(Path, file_type);
			}	
		}
		Path[len] = '\0';
	}
}


int main(){
	char path[10000];
	strcpy(path, ROOT);

	Recursion(path, FILE_TYPE);
	return 0;
}
