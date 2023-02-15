#include <stdio.h>
#include <stdlib.h>

int my_func(int a, int b, int (*func)(int val1, int val2)){
	return func(a, b);
}

int func(int value1, int value2);

int main(){
	int a;
	int b;
	scanf("%d %d", &a, &b);
	int res = my_func(a, b, &func);
	printf("%d\n", res);
	return 0;
}
