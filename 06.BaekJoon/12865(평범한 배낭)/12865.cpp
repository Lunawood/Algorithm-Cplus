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
			// �� �� �ִ� ���԰� ���� ���Ժ��� ū��� :
			// ������ ������ ��ġ or 
			// (�� �� �ִ� ���� - ���� ����)�� ��ġ���� �ִ밪�� ���� ������ ��ġ�� ��  
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
