#include<iostream>

using namespace std;
// �Ǻ���ġ��1
// ���̳��� ���α׷��� DP

int f[41];
int rec = 0, dp = 0;	// ���ȣ��, dp ���α׷��� ���� Ƚ��. 
int fib(int n) {	// �ڵ�1
    if (n == 1 or n == 2) {
    	return 1;
	}
	rec++;
	return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {	// �ڵ�2
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
	
	// ó�� ȣ���� Ƚ������ �߰� 
	cout << rec + 1 << " " << dp;
	
	return 0;
}
