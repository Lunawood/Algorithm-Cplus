#include <iostream>
using namespace std;

int a[1000001];

void dp(int n) {
	a[0] = 0;
	a[1] = 0;
	for(int i = 2; i <= n; i++){
		a[i] = 1 + a[i-1];
		if(i % 3 == 0){
			a[i] = min(a[i], 1 + a[i/3]);
		}
		if(i % 2 == 0){
			a[i] = min(a[i], 1 + a[i/2]);
		}
	}
	
	cout << a[n]; 
}

int main(void){
	int n;
	cin >> n;
	
	dp(n);
	
	return 0;
}
