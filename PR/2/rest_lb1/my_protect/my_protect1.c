#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	time_t t = time(NULL);
	struct tm *tm = gmtime(&t);
	if (tm->tm_mday % 2 == 0)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
