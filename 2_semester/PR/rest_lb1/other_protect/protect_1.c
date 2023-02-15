#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int n;
	scanf("%d", &n);
	time_t now = time(NULL);
	struct tm* tm = gmtime(&now);
	if ((tm->tm_wday + n)%7 == 0)
		printf("yes");
	else
		printf("no");
	return 0;
}
