#include <iostream>
#define MAX 100
using namespace std;

int n, m, k;
int a[MAX][MAX];
int b[MAX][MAX];

void input(int y, int x, int z[][MAX]){
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			scanf("%d", &z[i][j]);
		}
	}
}

int main(void){
	scanf("%d %d", &n, &m);
	input(n, m, a);
	
	scanf("%d %d", &m, &k);
	input(m, k, b);
	
	// c[1][1] = a[1][1] * b[1][1] + a[1][2] * b[2][1]
	// c[2][1] = a[2][1] * b[1][1] + a[2][2] * b[2][1]
	// c[3][1] = a[3][1] * b[1][1] + a[3][2] * b[2][1]
	
	// c[1][2] = a[1][1] * b[1][2] + a[1][2] * b[2][2]
	int c[MAX][MAX] = {0,};
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			for(int l = 0; l < m; l++){
				c[j][i] += a[j][l] * b[l][i];
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			printf("%d ", c[i][j]);
		} printf("\n");
	}
	
	return 0;
}
