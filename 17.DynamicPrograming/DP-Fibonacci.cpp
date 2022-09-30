#include<stdio.h>

// 메모이제이션 : 단순히 메모를 해놓는 것. 
int d[100];

// 다이나믹 프로그래밍(DP) : 하나의 문제는 단 한 번만 풀도록 하는 알고리즘
// 							대회에서 가장 많이 나오는 문제 
//							ex) 피보나치 수열 회귀 문제, 동일한 문제를 해결 
int dp(int x){
	if(x == 1) return 1;
	if(x == 2) return 1;
	// 0이 아니라면 이미 정답이 있음 
	if(d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void){
	printf("%d", dp(30));	// 50번째 피보나치수는 큰 수라 overflow가 일어남 
	
	return 0;
}

