#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#define MAX_LINES 100
#define LINE_SIZE 100
#define ROOT "./test_for_4"

void ReadFile(char *Path, char **arr, int *n){
	printf("%s\n", Path);
	FILE *file = fopen(Path, "r");
	if (file == NULL){return;}
	char *content = malloc(LINE_SIZE*sizeof(char));
	fgets(content, LINE_SIZE, file);
	arr[(*n)++] = content;
	fclose(file);
}


void Recursion(char *Path, char **arr, int *n){
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
		if (dt->d_type == DT_REG && strstr(dt->d_name, ".txt")){
			ReadFile(Path, arr, n);
		}
		if (dt->d_type == DT_DIR){
			Recursion(Path, arr, n);
		}
		Path[len] = '\0';
	
	}
	closedir(cur_dir);
}


int cmp(const void *a, const void *b){
	char *f = *(char **)a;
	char *s = *(char **)b;
	//printf("%s\t%s", f, s);
	return strcmp(f, s);
}

void Print(char **arr, int n, char *file_name){
	FILE *file = fopen(file_name, "w");
	if (file == NULL){return;}
	for (int i = 0; i < n; i++){
		fprintf(file, "%s", arr[i]);
		free(arr[i]);
	}
	fclose(file);
}


int main(){
	int n = 0;
	char *path = malloc(100*sizeof(char));
	strcpy(path, ROOT);
	char **arr = malloc(MAX_LINES*sizeof(char*));

	Recursion(path, arr, &n);
	printf("%d\n", n);
	for (int j = 0; j < n; j++){
		printf("%s", arr[j]);
	}
	qsort(arr, n, sizeof(char*), cmp);
	Print(arr, n, "out.txt");
	return 0;
}
