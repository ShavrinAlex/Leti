#include <stdio.h>
#include <stdlib.h>
#define N 5

void read_arr(int arr[], int len){
	for(int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}
}

void new_arr(int arr_A[], int arr_B[],  int len, int n){
	for(int i = 0; i < len; i++){
		int s = 0;
		int l = i - n;
		int r = i;
		for(int j = l; j <= r; j++){
			if(j >= 0){
				s += arr_A[j];
			}
		}
		arr_B[i] = abs(s);		
	}
}

void print_arr(int arr[], int len){
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int arr_A[N];
	int arr_B[N];
	int n;
	scanf("%d", &n);
	printf("n = %d\n", n);
	read_arr(arr_A, N);
	new_arr(arr_A, arr_B, N, n);
	print_arr(arr_B, N);
	return 0;
}
