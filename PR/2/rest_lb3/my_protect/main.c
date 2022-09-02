#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#define ROOT "./root"

void ReadFile(char *Path, char **arr, int *n){
	FILE *file = fopen(Path, "r");
	if (file == NULL){return;}
	char *content = malloc(200*sizeof(char));
	fgets(content, 200, file);
	arr[(*n)++] = content;
	fclose(file);
}

void Recursion(char *Path, char **arr, int *n){
	DIR *cur_dir = opendir(Path);
	if (cur_dir == NULL){return;}

	struct dirent *dt;
	while (dt = readdir(cur_dir)){
		int len = strlen(Path);
		strcat(Path, "/");
		strcat(Path, dt->d_name);

		if (dt->d_type == DT_DIR && strcmp(dt->d_name, ".") && strcmp(dt->d_name, "..")){
			Recursion(Path, arr, n);
		}

		if (dt->d_type == DT_REG){
			ReadFile(Path, arr, n);
		}

		Path[len] = '\0';
	}

	closedir(cur_dir);
}

void PrintToFile(char **arr, int n){
	FILE *file = fopen("a.txt", "w");
	if (file == NULL){return;}
	for (int i = 0; i < n; i++){
		fprintf(file, "%s", arr[i]);
		free(arr[i]);
	}
	free(arr);
	fclose(file);
}

int cmp(const void *a, const void *b){
	char *f = (char *)a;
	char *s = (char *)b;
	return strcmp(f, s);
}

int main(){
	int n = 0;
	char **arr = malloc(1000*sizeof(char *));
	char *path = malloc(1000*sizeof(char));
	strcpy(path, ROOT);
	Recursion(path, arr, &n);
	qsort(arr, n, sizeof(char *), cmp);
	PrintToFile(arr, n);
	free(path);
	return 0;
}
