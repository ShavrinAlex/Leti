#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc <= 1){
		printf("%s: file not entred\n", argv[0]);
	} else{
		FILE *f;
		f = fopen(argv[1], "r");
		if (f){
			printf("%s: %s file open\n", argv[0], argv[1]);
			char str[64];
			while (fgets(str, sizeof(str), f)){
				printf("%s", str);
			}
			fclose(f);
		} else{
			printf("%s: %s file can't be open\n", argv[0], argv[1]);
		}
	}
	return 0;
}
