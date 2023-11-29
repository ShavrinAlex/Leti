#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#define ROOT "./test_for_5_2"


typedef struct Node{
	char *path;
	int size;
} Node;


Node *createNode(char *path, int size){
	Node *elem = malloc(sizeof(Node));
	elem->path = path;
	elem->size = size;
	return elem;
}

void freeNode(Node *elem){
	free(elem->path);
	free(elem);
}


void Recursion(char *path, Node **dict, int *count_elem){
	DIR *cur_dir = opendir(path);
	if (cur_dir == NULL){return;}
	struct dirent *dt;
	while (dt = readdir(cur_dir)){
		int len = strlen(path);
		char *Path = malloc(100*sizeof(char));
		strcpy(Path, path);
		strcat(Path, "/");
		strcat(Path, dt->d_name);
		if (dt->d_type == DT_DIR && strcmp(dt->d_name, ".") && strcmp(dt->d_name, "..")){
			Recursion(Path, dict, count_elem);
		}
		if (dt->d_type == DT_REG){
			FILE *file = fopen(Path, "r");
			if (file == NULL){return;}
			int base_size = 1000;
			char *content = malloc(base_size * sizeof(char));
			fgets(content, base_size, file);
			dict[(*count_elem)++] = createNode(Path, strlen(content));
		}
		path[len] = '\0';
	}
	closedir(cur_dir);
}

int cmp(const void *a, const void *b){
	Node *f = *(Node **)a;
	Node *s = *(Node **)b;
	if (f->size == s->size)
		return strcmp(f->path, s->path);

	if (f->size > s->size)
		return 1;

	if (f->size < s->size)
		return -1;

	return 0;
}

void Print(Node **dict, int count_elem){
	for (int i = 0; i < count_elem; i++){
		printf("%s; %d\n", dict[i]->path, dict[i]->size);
		free(dict[i]);
	}
	free(dict);
}

int main(){
	int count_elem = 0;
	Node **dict = malloc(100*sizeof(Node*));

	char *path = malloc(1024 * sizeof(char));
	strcpy(path, ROOT);

	Recursion(path, dict, &count_elem);

	qsort(dict, count_elem, sizeof(Node*), cmp);

	Print(dict, count_elem);
	return 0;
}
