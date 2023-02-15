#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int cmp(const void *a, const void *b){
	const int *f = (const int *)a;
	const int *s = (const int *)b;
	if (abs(*f) < abs(*s))
		return 1;
	if (abs(*f) > abs(*s))
		return -1;
	return 0;
}


int main(){
	int *a = malloc(N*sizeof(int));
	clock_t t;

	//read arr
	for (int i = 0; i < N; i++)
		scanf("%d", (a+i));

	//sort
	t = clock();
	qsort(a, N, sizeof(int), cmp);
	t = clock() - t;

	//print ans
	for (int i = 0; i < N; i++)
		printf("%d ", *(a+i));
	printf("\n%f sec\n", (float)t/CLOCKS_PER_SEC);
	
	return 0;

}
