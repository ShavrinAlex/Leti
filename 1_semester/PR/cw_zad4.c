#include <stdio.h>
#define N 4

int check_mask(int arr[]){
	int check = 0;
	int change = 0;
	for (int x = N-1; x >= 0; x--){
		for (int i = 0; i < 8; i++){
			if (check == 0){
				if ((arr[x] & (1<<i)) != check){
					if (i == 0 && x == 3){
						check = 1;
						continue;
					}
					if (change == 1){
						return -1;
					}
					if (change == 0){
						change += 1;
						check = 1;
					}
				}
			}
			else{
				if ((arr[x] & (1<<i)) == 0){
					if (change == 1){
						return -1;
					}
					if (change == 0){
						change += 1;
						check = 0;
					}
				}
			}
		}
	}
	return 1;
}

int check_ip(int arr[]){
	for (int i = 0; i < N; i++){
		if (arr[i] < 0 || arr[i] > 255)
			return -1;
	}
	return 1;
}

void get_arr(int arr[]){
	char c;
	for (int i = 0; i < N; i++){
		scanf("%d%c", &arr[i], &c);
	}
}

void get_adress(int arr_ip[], int arr_msk[], int arr_adr[]){
	for (int i = 0; i < N; i++){
		arr_adr[i] = arr_ip[i] & arr_msk[i];
	}
}

void print_adr(int arr[]){
	for (int i = 0; i < N; i++){
		if (i != 3){
			printf("%d.", arr[i]);
		}
		else{
			printf("%d\n", arr[i]);
		}
	}
}

int main(){
	int ip[N];
	int msk[N];
	int adr[N];
	get_arr(ip);
	get_arr(msk);
	if (check_ip(ip) == -1){
		printf("wrong IP\n");
		return 0;
	}
	if (check_mask(msk) == -1){
		printf("wrong MASK\n");
		return 0;
	}
	get_adress(ip, msk, adr);
	print_adr(adr);	
	return 0;
}
