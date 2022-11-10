#include<iostream>

using namespace std;

int dp[100001];

// �ð������� 1���̹Ƿ� DP�� Ǯ����Ѵ�.
// 1~N��°���� ���Ѱ��� DP[N]�� ���� 

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		int num;
		cin >> num;
		dp[i] = dp[i-1] + num;
	}
	
	for(int i = 1; i <= M; i++){
		int s, e;
		cin >> s >> e;
		cout << dp[e] - dp[s-1] << '\n';
	}
	
	return 0; 
}
