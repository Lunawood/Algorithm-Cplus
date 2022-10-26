#include <stdio.h>

int N, M;

int main(void){
	scanf("%d %d", &N, &M);
	
	int A[N][M] = {0, }, x;
	int B[N][M] = {0, };
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &x);
			A[i][j] = x;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &x);
			B[i][j] = x;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%d ", A[i][j] + B[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
