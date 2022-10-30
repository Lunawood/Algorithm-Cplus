#include<iostream>

using namespace std;
// 피보나치수1
// 다이나믹 프로그래밍 DP

int f[41];
int rec = 0, dp = 0;	// 재귀호출, dp 프로그래밍 실행 횟수. 
int fib(int n) {	// 코드1
    if (n == 1 or n == 2) {
    	return 1;
	}
	rec++;
	return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {	// 코드2
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= n; i++){
		dp++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main(void){
	int N;
	cin >> N;
	fib(N);
	fibonacci(N);
	
	// 처음 호출한 횟수까지 추가 
	cout << rec + 1 << " " << dp;
	
	return 0;
}
