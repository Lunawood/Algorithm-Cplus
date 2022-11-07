#include<iostream>

using namespace std;

int arr[10001];
int dp[10001];

void DP(int n){
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[2], max(arr[2] + arr[3], arr[1] + arr[3]));
	for(int i = 4; i <= n; i++){
		dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]));
	}
	cout << dp[n] << endl;
}

int main(void){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	} 
	DP(N);
	return 0;
}
