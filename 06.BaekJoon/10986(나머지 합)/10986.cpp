#include <iostream>
#define MAX 1001
using namespace std;

long long a[MAX];
long long tot;
long long result;

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		tot += x;
		a[tot % m]++;		
	}
	
	for(int i = 0; i <= 1000; i++){
		result += a[i] * (a[i] - 1) / 2;
	}
	
	printf("%d\n", a[0] + result);
	return 0;
}
