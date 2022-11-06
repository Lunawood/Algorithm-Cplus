#include <iostream>

using namespace std;

int N, result=0;
int d[101][10];
void dp(int n){
	fill(&d[0][0], &d[0][10], 1);
	d[0][0] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0) d[i][j] = d[i-1][j+1];
			if(j == 9) d[i][j] = d[i-1][j-1];
			if(j > 0 and j < 9) d[i][j] = d[i-1][j-1] + d[i-1][j+1];
			
			d[i][j] %= 1000000000;
		}
	}
}

int main(void){
	cin >> N;
	dp(N);
	for(int i = 0; i < 10; i++){
		result += d[N-1][i];
	}
	cout << result;
	return 0;
} 
