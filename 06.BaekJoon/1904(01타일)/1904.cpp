#include<iostream>

using namespace std;

int f[1000001];

// F(n+2) = F(n+1) + F(n)
void fi(int n){
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= n; i++){
		f[i] = (f[i-1] + f[i-2]) % 15746;
	}
	cout << f[n];
}
int main(void){
	int N;
	cin >> N;
	fi(N);	
	return 0;
}
