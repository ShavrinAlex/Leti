#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#define ROOT "./test_for_5_1"


typedef struct Node{
	char *file_name;
	char *content;
	int count;
	Node *next;
} Node;


typedef struct Dict{
	Node *head;
} Dict


Node *createNode(char *file_name, char *content){
	Node *elem = malloc(sizeof(Node));
	elem->file_name = malloc(strlen(file_name)+1);
	elem->content = malloc(strlen(content)+1);
	strcpy(elem->file_name, file_name);
	strcpy(elem->content, content);
	elem->count = 1;
	elem->next = NULL;
	return elem;
}


void freeNode(Node *elem){
	free(elem->file_name);
	free(elem->content);
	free(elem);
}


Dict *createDict(){
	Dict *dict = malloc(sizeof(Node));
	dict->head = NULL;
	return dict;
}


void freeDict(Dict *dict){
	Node *cur = dict->head;
	Node *prev = NULL;
	while (cur){
		prev = cur;
		cur = cur->next;
		freeNode(prev);
	}
	free(dict);
}


void add(Dict *dict, char *file_name, char *content){
	Node *cur = dict->head;
	Node *prev = NULL;
	while (cur && strcmp(file_name, cur->file_name)){
		prev = cur;
		cur = cur->next;
	}
	if (cur && !strcmp(file_name, cur->file_name)){
		cur->count++;
		return;
	}
	while (cur){
		prev = cur;
		cur = cur->next;
	}
	if (prev){
		prev->next = createNode(file_name, content);
	} else{
		dict->head = createNode(file_name, content);
	}
}


void Recursion(Dict *dict, char *Path){
	DIR *cur_dir = opendir(Path);
	if (cur_dir == NULL){return;}

	struct dirent *dt;
	while (dt = readdir(cur_dir)){

		int len = strlen(Path);
		strcat(Path, "/");
		strcat(Path, dt->d_name);

		if (dt->d_type == DT_DIR && strcmp(dt->d_name, ".") && strcmp(dt->d_name, "..")){
			Recursion(dict, Path);
		}

		if (dt->d_type == DT_REG){
			FILE *file = fopen(Path);
			if (file == NULL){return;}
			int base_size = 1000
			char *content = malloc(base_size*sizeof(char));
			char buffer[base_size];
			while (fgets(buffer, base_size, file)){
				if (strlen(buffer) + strlen(content) + 1 > base_size){
					base_size += 1000;
					content = realloc(content, base_size);
				}
				strcat(content, buffer);
			}
			add(dict, dt->d_name, content);
			free(content);
		}
		Path[len] = '\0';
	}
	closedir(cur_dir);
}

void findMax(Dict *dict){
	Node *cur = dict->head;
	int max = 0;
	char max_name[100];
	while (cur){
		if (cur->count > max){
			max = cur->count;
			strcpy(max_name, cur->file_name);
		}
		if (cur->count == max && strcmp(max_name, cur->file_name) < 0){
			strcpy(max_name, cur->file_name);
		}
		cur = cur->name;
	}
	printf("%d; %s", max, max_name);
}

int main(){
	Dict *dict = createDict();

	char path = malloc(1024*sizeof(char));
	strcpy(path, ROOT);

	Recursion(dict, path);

	findMax(dict);

	freeDict(dict);
	return 0;
}
