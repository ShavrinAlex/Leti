#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


#define ROOT_DIRECTORY "./labyrinth"
#define OUTPUT_FILE_NAME "result.txt"
#define SEARCH_FILE_NAME "file.txt"
#define BASE_SIZE 500


typedef struct Node{
	char *path;
	struct Node *previous;
	struct Node *next;
} Node;


Node* CreateNode(char *path){
	char *way = malloc(BASE_SIZE*sizeof(char));
	strcpy(way, path);
	Node *elem = malloc(sizeof(Node));
	elem->path = way;
	elem->previous = NULL;
	elem->next = NULL;
	return elem;
}


void PushBack(Node *head, char *path){
	Node *elem = CreateNode(path);
	Node *cur = head;
	while (cur->next){
		cur = cur->next;
	}
	cur->next = elem;
	elem->previous = cur;
}


void PrintToFile(Node *head, char *file_name){
	Node *cur = head;
	while (cur->next){
		cur = cur->next;
	}

	FILE *file = fopen(file_name, "w");
	if (file == NULL){return;}

	while (cur){
		fprintf(file, "%s\n", cur->path);
		cur = cur->previous;
	}
	fclose(file);
}


void FreeList(Node *head){
	Node *cur = head;
	while (cur->next){
		cur=cur->next;
		free(cur->previous);
	}
	free(cur);
}


int Recursion(char *DirectoryPath, char *search_file_name, Node **list){
	DIR *current_directory = opendir(DirectoryPath);
	if (current_directory == NULL){
		return -1;
	}

	struct dirent *dp;

	while (dp = readdir(current_directory)){
		if (dp->d_type == DT_DIR && (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))){
			continue;
		}

		int path_length = strlen(DirectoryPath);
		strcat(DirectoryPath, "/");
		strcat(DirectoryPath, dp->d_name);
			
		if (dp->d_type == DT_REG && !strcmp(dp->d_name, search_file_name)){
			//read file
			FILE *file = fopen(DirectoryPath, "r");

			if (file == NULL){return -1;}

			char content[BASE_SIZE];
			while(fgets(content, BASE_SIZE, file)){

				if (strstr(content, "\n") && strlen(content)){
					*strstr(content, "\n") = '\0';
				}

				//checking for minotaur
				if (!strcmp(content, "Minotaur")){
					*list = CreateNode(DirectoryPath); 
					closedir(current_directory);
					fclose(file);
					return 1;	
				}
			
				//checking for deadlock
				if (!strcmp(content, "Deadlock")){
					closedir(current_directory);
					fclose(file);
					return 0;
				}

				//maybe it is link
				char other_way[BASE_SIZE];
				strcpy(other_way, ROOT_DIRECTORY);
				int out = Recursion(other_way, strstr(content, " ")+1, list);
				if (out){
					PushBack(*list, DirectoryPath);
					closedir(current_directory);
					fclose(file);
					return 1;
				}

			}
		}

		if (dp->d_type == DT_DIR){
			int out = Recursion(DirectoryPath, search_file_name, list);
			if (out){
				closedir(current_directory);
				return 1;
			}
		}
		DirectoryPath[path_length] = '\0';	
	}
	closedir(current_directory);
	return 0;
}


int main(){
	Node *list;
	char path[BASE_SIZE];
	strcpy(path, ROOT_DIRECTORY);

	Recursion(path, SEARCH_FILE_NAME, &list);
	
	PrintToFile(list, OUTPUT_FILE_NAME);

	FreeList(list);

	return 0;
}
