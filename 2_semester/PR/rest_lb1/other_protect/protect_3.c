#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 11

struct Sent{
	char c;
	int pos;
};

int cmp(const void *a, const void *b){
	const struct Sent *f = (const struct Sent *)a;
	const struct Sent *s = (const struct Sent *)b;
	if(f->c==s->c)return 0;
	if(f->c>s->c)return 1;
	if(f->c<s->c)return -1;
}

int main(){
	char arr[N];
	char x;
	char c;
	scanf("%s%c", arr, &c);
	scanf("%c%c", &x, &c);
	struct Sent *w = malloc(strlen(arr)*sizeof(struct Sent));
	for (int i = 0; i < strlen(arr); i++){
		w[i].c = arr[i];
		w[i].pos = i;
	}

	//sort
	qsort(w, strlen(arr), sizeof(struct Sent), cmp);
	for (int i = 0; i < strlen(arr); i++)
		printf("%d\t%c\n", w[i].pos, w[i].c);
	
	//bsearch
	struct Sent *p = bsearch(&x, w, strlen(arr), sizeof(struct Sent), cmp);	
	printf("%d\n", p->pos);
	return 0;
}
