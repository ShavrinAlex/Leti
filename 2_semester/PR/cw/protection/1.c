#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pred1(const void *a){
	const int n = *(const int *)a;
	if (n % 2 == 0){
		return 1;
	}
	return 0;
}

int pred2(const void *a){
	const double f = *(const double *)a;
	//float cc, dc;
	//dc = modff(f, &cc);
	//if ((fabs(dc) <= 0.000001) && (abs((int)f) % 2 == 0)){
		//return 1;
	//}	
	if (((int)f % 2 == 0) && (fabs(fabs(f)- fabs((int)f)) <= 0.000001)){
		return 1;
	}

	return 0;
}

int count_if(void* base, size_t num, size_t size, int (*pred)(const void*)){
	int count = 0;
	for (size_t i = 0; i < num; i++){
		if (pred(base + i*size)){
			count++;
		}
	}
	return count;
}

int main(){
	size_t size;
	int arr1[20];
	double arr2[20];
	int res = 0;
	char c;
	scanf("%ld%c", &size, &c);
	if (size == 4){
		for (int i = 0; i < 20; i++){
			scanf("%d%c", &arr1[i], &c);
		}
		res = count_if(arr1, 20, size, pred1);	
	}else{
		for (int i = 0; i < 20; i++){
			scanf("%lf%c", &arr2[i], &c);
		}		
		res = count_if(arr2, 20, size, pred2);	
	}
	printf("%d\n", res);
	return 0;
}
