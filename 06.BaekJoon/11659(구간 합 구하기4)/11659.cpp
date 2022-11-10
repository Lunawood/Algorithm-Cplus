#include<iostream>

using namespace std;

int dp[100001];

// 시간제한이 1초이므로 DP로 풀어야한다.
// 1~N번째까지 더한값을 DP[N]에 저장 

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
