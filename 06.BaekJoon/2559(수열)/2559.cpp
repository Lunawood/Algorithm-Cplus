#include <iostream>
#define MAX 100001
using namespace std;

// 수열 11659 와 비슷한 문제

int a[MAX];
int dp[MAX];
int N, K;

void DP(){
	for(int i = 1; i <= K; i++){
		dp[0] += a[i];
	}
	int result = dp[0];
	
	for(int i = 1; i <= N - K; i++){
		dp[i] = dp[i-1] + a[i + K] - a[i];
		result = max(result, dp[i]);
	}
	
	printf("%d", result);
}

int main(void){
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++){
		int x;
		scanf("%d", &a[i]);
	}	
	
	DP();
	
	return 0;
} 
