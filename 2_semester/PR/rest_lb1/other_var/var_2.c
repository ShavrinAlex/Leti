#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int cmp(const void* a, const void* b){
	const int *f = (const int*)a;
	const int *s = (const int*)b;
	if (*f > *s)
		return 1;
	if (*f < *s)
		return -1;
	return 0;
}


int main(){
	int *a = malloc(N*sizeof(int));
	clock_t t1;
	clock_t t2;
	int k = 0;

	//read arr
	for (int i = 0; i < N; i++)
		scanf("%d", (a+i));

	//sort
	qsort(a, N, sizeof(int), cmp);

	//bsearch
	t1 = clock();
	int *pos = (int*)bsearch(&k, a, N, sizeof(int), cmp);
	t1 = clock() - t1;

	//print ans bsearch
	if (pos)
		printf("exists\n");
	else
		printf("doesn't exist\n");
	printf("bsearch %f sec\n", (float)t1/CLOCKS_PER_SEC);

	//enum
	t2 = clock();
	int c = 0;
	for (int i = 0; i < N; i++){
		if (k == *(a+i)){
			c++;
			break;
		}
	}
	t2 = clock() - t2;

	//print ans enum
	if (c)
		printf("exists\n");
	else
		printf("doesn't exist\n");
	printf("enum %f sec\n", (float)t2/CLOCKS_PER_SEC);

	return 0;
}
