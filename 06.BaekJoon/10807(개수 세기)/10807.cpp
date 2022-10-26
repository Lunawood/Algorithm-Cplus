#include <stdio.h>

int a[201];
int N, x;

int main(void){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &x);
		a[x + 100]++;
	}
	scanf("%d", &x);
	printf("%d", a[x+100]);
	return 0;
}
