#include <iostream>

using namespace std;

// �������� m���� n�� �̱� 
void dp(int n, int m){
	long long a = 1, b = 1;
	// m!/n!(m-n)!
	for(int i = m; i > m - n; i--){
		b *= i;
		b /= a;
		a++;
	} 
	
	printf("%d\n", b);
}

int main(void){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		dp(n, m);
	}
	return 0;
}
