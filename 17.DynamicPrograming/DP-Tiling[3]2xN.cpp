#include <stdio.h>

// D[n] = 2 * D[n-1] + 3 * D[n-2] + 2 * D[n-3] + 2 * D[n-4] + ...
// D[n] = 2 * D[n-1] + 3 * D[n-2] + 2 * (D[n-3] + D[n-4] + D[n-5] + ...)
long long int d[1000001][2];

long long int dp(int x){
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for(int i = 3; i <= x; i++){
		// 2 * (D[n-3] + D[n-4] + D[n-5] + ...)=
		// 2 * (D[n-3] + D[n-4] + D[n-5] + ... + {D[n-k})
		d[i][1] = (d[i-1][1] + d[i-3][0]) % 1000000007;
		d[i][0] = (2 * d[i-1][0] + 3 * d[i-2][0] + 2 * d[i][1]) % 1000000007;
	}
	return d[x][0];
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
	
	return 0;
}
