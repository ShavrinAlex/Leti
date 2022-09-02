#include <stdio.h>
#include <stdlib.h>

int func1(int a){
	return a*2;
}

int func2(int a){
	return a * a * a;
}

int func3(int a){
	return abs(a);
}

void forEachElement(int *arr, int n, int (*func)(int a)){
	for (int i = 0; i < n; i++){
		*(arr+i) = func(*(arr+i));
	}
}

void printArr(int *arr, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int arr[500];
	char c = '\n';
	int i = 0;
	while (c == '\n'){
		scanf("%d%c", &arr[i++], &c);
	}
	int choice = arr[i-1];
	switch(choice){
		case 1:
			forEachElement(arr, i-1, func1);
			break;
		case 2:
			forEachElement(arr, i-1, func2);
			break;
		case 3:
			forEachElement(arr, i-1, func3);
			break;
		default:
			printf("Error\n");
			return 0;
	}
	printArr(arr, i-1);	
	return 0;
}
