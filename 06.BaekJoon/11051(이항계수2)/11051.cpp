#include<iostream>

using namespace std;

int d[1001][1001];

void fi(int n, int m){
	for(int i = 1; i <= n; i++){
		d[i][i] =1;
		d[i][0] =1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(d[i][j] == 1) continue;
			d[i][j] = (d[i-1][j-1] + d[i-1][j]) % 10007;
		}
	}
	
	printf("%d\n", d[n][m] % 10007);
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	
	fi(n,m);
	return 0;
}
