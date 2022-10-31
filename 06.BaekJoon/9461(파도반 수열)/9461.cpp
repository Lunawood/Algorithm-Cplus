#include<iostream>

using namespace std;

// F(n) = F(n-1) + F(n-5)
long long int f[101];

void tri(int n){
	f[1] = 1;	
	f[2] = 1;
	f[3] = 1;
	f[4] = 2;
	f[5] = 2;
	for(int i = 6; i <= n; i++){
		f[i] = f[i-1] + f[i-5];
	}
	cout << f[n] << endl;
} 

int main(void){
	int N, T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;
		tri(N);
	}
	return 0;
}

