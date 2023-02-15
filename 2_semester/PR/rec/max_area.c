#include <stdio.h>

void readPict(int n, int m, int pict[n][m]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &pict[i][j]);
		}
	}
}

int area(int i, int j, int n, int m, int pict[][m]){
	if (i < 0 || i >= n || j < 0 || j >= m || pict[i][j] == 0)
		return 0;
	pict[i][j] = 0;
	return 1 + area(i+1, j, n, m, pict) +  area(i, j+1, n, m, pict) + area(i-1, j, n, m, pict) + area(i, j-1, n, m, pict);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int pict[n][m];
	readPict(n, m, pict);
	int maxArea = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int curArea = area(i, j, n, m, pict);
			if (maxArea < curArea) 
				maxArea = curArea;
		}
	}
	return 0;
}
