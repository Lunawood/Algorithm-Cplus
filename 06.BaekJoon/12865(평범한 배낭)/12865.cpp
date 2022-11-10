#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int N, K, W[MAX], V[MAX];
int DP[MAX][100001];
int result = 0; 

void dp(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			// 들 수 있는 무게가 짐의 무게보다 큰경우 :
			// 이전의 무게의 가치 or 
			// (들 수 있는 무게 - 짐의 무게)의 가치들의 최대값과 지금 무게의 가치의 합  
			if(j >= W[i]) DP[i][j] = max(DP[i-1][j], DP[i-1][j - W[i]] + V[i]);
			else DP[i][j] = DP[i-1][j];
			
			result = max(result, DP[i][j]);
		}
	}
	
	cout << result;
}

int main(void){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> W[i] >> V[i];
	}
	
	dp();
	
	return 0;
} 
