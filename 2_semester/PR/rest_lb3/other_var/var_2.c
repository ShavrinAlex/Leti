#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


#define ROOT_DIRECTORY "./tmp_var_2" 
#define OUTPUT_FILE_NAME "result.txt"
#define PATH_SIZE 10000


int ReadFile(char *FilePath, char *procedure){
	FILE *file = fopen(FilePath, "r");
	
	//error checking
	if (file == NULL || procedure == NULL){return 0;}
	

	//read content
	char string[100];
	fgets(string, 100, file);
	
	//set n
	int n  = 0;
	if (strcmp(procedure, "mul") == 0){
		n++;
	}
	
	//calculate n
	char *pch = strtok (string, " \n");
	while (pch){
		if (strcmp(procedure, "add") == 0){
			n += atoi(pch);
		}else{
			n *= atoi(pch);
		}
		pch = strtok (NULL, " \n");
	}

	return n;
}


int Recursion(char *DirectoryPath, char *procedure){
	//error checking
	if (DirectoryPath == NULL){return 0;}
	
	DIR *current_directory = opendir(DirectoryPath);
	//error checking
	if (current_directory == NULL){return 0;}
	
	struct dirent *dt = readdir(current_directory);

	//set n
 	int n = 0;
	if (procedure != NULL && strcmp(procedure, "mul") == 0){
		n += 1;
	}

	while (dt){
		//checking for start directory or exit
		if (dt->d_type == DT_DIR && (strcmp(dt->d_name, ".") == 0 || strcmp(dt->d_name, "..") == 0)){
			dt = readdir(current_directory);
			continue;
		}
		//не нужно тк он сохраняется на директорию выше
		//checkong for output file
		//if (dt->d_type == DT_REG && strcmp(dt->d_name, OUTPUT_FILE_NAME) == 0){
		//	dt = readdir(current_directory);
		//	continue;
		//}
		
		//create path to the directory or file
		char path[PATH_SIZE];
		strcpy(path, DirectoryPath);
		strcat(path, "/");
		strcat(path, dt->d_name);
		
		//fyle type checking
		if (dt->d_type == DT_REG){
			if (strcmp(procedure, "add") == 0){
				n += ReadFile(path, procedure); 
			}
			if (strcmp(procedure, "mul") == 0){
				n *= ReadFile(path, procedure); 
			}
		}else{
			if (dt->d_type == DT_DIR){
				//get next procedure
				char next_procedure[4];
				strcpy(next_procedure, dt->d_name);


				if (strcmp(procedure, "mul") == 0){
					n *= Recursion(path, next_procedure);
				}else{
					n += Recursion(path, next_procedure);
				}
			}
		}
		//getting new directory element
		dt = readdir(current_directory);
	}
	closedir(current_directory);
	return n;
}


void PrintToFile(int n, char* file){
	FILE *f = fopen(file, "w");
	if (f == NULL){return;}
	fprintf(f, "%d\n", n);
	fclose(f);
}


int main(){
	char *procedure = "nul\0";
       	int N = Recursion(ROOT_DIRECTORY, procedure);
	PrintToFile(N, OUTPUT_FILE_NAME);
	printf("%d\n", N);
	return 0;
}
