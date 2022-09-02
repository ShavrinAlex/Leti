#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

struct User{
	char surname[100];
	char name[100];
};

int cmp(const void *a, const void *b){
	const struct User *f = (const struct User*)a;
	const struct User *s = (const struct User*)b;
	if (strcmp(f->surname, s->surname))
		return strcmp(f->surname, s->surname);
	else{
		return strcmp(f->name, s->name);
	}
}

int main(){
	struct User *users = malloc(N*sizeof(struct User));
	int len = 0;
	char s[100];
	fgets(s, 100, stdin);
	printf("%s\n", s);
	printf("%d\t%d", strlen(s), strcmp(s, "!"));
	int i = 0;
	while (strcmp(&s[0], "!\n") != i){
		char *pt;
		pt = strtok(s, " ");
		printf("1\n");
		int c = 0;
		while (pt != NULL){
   			if (!c){
				//printf("2.1\n");
				strcpy(users[i].surname, pt);
			}else{
				//printf("2.2\n");
				strcpy(users[i].name, pt);
			}
			c++;
			//printf("%s\n", pt);
    			pt = strtok (NULL, " ,.-");
  		}
		//printf("3\n");
		i++;
		fgets(s, 100, stdin);
		//printf("%s\n", s);
	}
	//for (len; len < N; len++){
	//	scanf("%s %s", users[len].surname, users[len].name);
	//}
		
	for (int i = 0; i < len; i++){
                printf("%s %s\n", users[i].surname, users[i].name);
	}
	//qsort
	qsort(users, len, sizeof(struct User), cmp);
	for (int i = 0; i < len; i++){
		printf("%s %s\n", users[i].surname, users[i].name);
	}
	return 0;
}
