#include <iostream>
#define MOD 1000000007
using namespace std;

long long ans[2][2] = {{1, 1}, {1, 0}};
long long a[2][2] = {{1, 1}, {1, 0}};
long long tmp[2][2]; 
long long n;

void func(long long x[2][2], long long y[2][2]){
	// Çà·Ä °ö
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			tmp[i][j] = 0;
			for(int k = 0; k < 2; k++){
				tmp[i][j] += x[i][k] * y[k][j];
			}
			tmp[i][j] %= MOD;
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			x[i][j] = tmp[i][j];
		}
	}
}

int main(void){
	cin >> n;
	
	while(n){
		if(n % 2 == 1) func(ans, a);
		func(a, a);
		n/=2;
	}
	
	cout << ans[1][1] % MOD <<'\n';
	
	return 0;
}                                                   
