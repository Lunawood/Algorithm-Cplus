#include<stdio.h>
#include<algorithm>
using namespace std;

// 계수정렬 : 조건부 정렬. 

int a[10001];
int N;
int x;

int main(void){
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &x);
		a[x]++;
	}	
	
	for(int i = 0; i < 10001; i++){
		while(a[i] != 0){
			printf("%d\n", i);
			a[i]--;
		}
	}
	return 0;
}
