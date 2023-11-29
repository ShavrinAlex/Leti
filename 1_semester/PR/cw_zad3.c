#include <stdio.h>

void read_arr(long int arr[], int len){
	for (int i = 0; i < len; i++){
		scanf("%ld", &arr[i]);
	}
}

long int sum(long int arr[], int len){
	long int s = 0;
	for (int i = 0; i < len; i+=2){
		s += arr[i];
	}
	return s;
}
int main(){
	int n;
	scanf("%d", &n);
	long int arr[n];
	read_arr(arr, n);
	printf("%ld\n", sum(arr, n));
	return 0;
}
