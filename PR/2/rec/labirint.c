#include <stdio.h>
#include <stdlib.h>

void readLab(int **arr, int n, int m){
	    for (int i = 1; i < n+1; i++){
		            for (int j = 1; j < m+1; j++){
				                scanf("%d", &arr[i][j]);
						        }
			        }
	        for(int j = 0; j<m+2; j++)
			        arr[0][j] = 1;
		    for(int i = 0; i<n+2; i++)
			            arr[i][0] = 1;
		        for(int j = 0; j<m+2; j++)
				        arr[n+1][j] = 1;
			    for(int i = 0; i<n+2; i++)
				            arr[i][m+1] = 1;
}

void printLab(int **arr, int n, int m){
	    for (int i = 0; i < n+2; i++){
		            for (int j = 0; j < m+2; j++){
				                printf("%d ", arr[i][j]);
						        }
			            printf("\n");
				        }
}

void fill(int **arr, int i, int j, int n, int m){
	    if (i == n && j == m){
		            printf("exists\n");
			            exit(0);
				        }
	        arr[i][j] = 2;
		    if (arr[i+1][j] == 0)
			            fill(arr, i+1, j, n, m);
		        if (arr[i][j+1] == 0)
				        fill(arr, i, j+1, n, m);
			    if (arr[i-1][j] == 0)
				            fill(arr, i-1, j, n, m);
			        if (arr[i][j-1] == 0)
					        fill(arr, i, j-1, n, m);
}

int main() {
	    int n, m;
	        scanf("%d %d", &n, &m);
		    int **arr;
		        arr = malloc((n+2)*sizeof(int *));
			    for (int i = 0; i < n+2; i++){
				            arr[i] = malloc((m+2)*sizeof(int));
					        }
			        readLab(arr, n, m);
				    printLab(arr, n, m);
				        fill(arr, 1, 1, n, m);
					    printf("doesn't exist\n");
					        return 0;
}
