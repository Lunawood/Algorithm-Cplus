#include <iostream>
#define MOD 1000000007
using namespace std;

long long int k, n;

long long int pow(long long int x, long long int i){
	long long int p = 1;
	
	while(i){
		if(i % 2) p = (p * x) % MOD;
		
		x = (x * x) % MOD;
		i /= 2;
	}
	
	return p;
}

int main(void){
	scanf("%d %d", &n, &k); 
	
	long long int a = 1, b = 1;
	
	for(int i = n; i >= n-k+1; i--) a = (a * i) % MOD;	// N * N-1 ... * N-K+1
	for(int i = 2; i <= k; i++) b = (b * i) % MOD;	// K!
	
	printf("%lld\n", (a * pow(b, MOD-2)) % MOD);
	
	return 0;
}
