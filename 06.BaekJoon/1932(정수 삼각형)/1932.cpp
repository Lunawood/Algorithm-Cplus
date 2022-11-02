#include <iostream>
#include <cmath>
using namespace std;

int t[500][500];
int mymax = 0;

void Max(int num){
	if(mymax < num){
		mymax = num;
	}
}
void dp(int N){
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){
				t[i][j] += t[i-1][j];
			} else if(i == j){
				t[i][j] += t[i-1][j-1];
			} else {
				t[i][j] += max(t[i-1][j-1], t[i-1][j]);
			}
		}
	}
}

int main(void){
	int N, x;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			cin >> x;
			t[i][j] = x;
		}
	}
	
	dp(N);
	
	for(int i = 0; i < N; i++){
		Max(t[N-1][i]);
	}
	
	cout << mymax;
	return 0;
}
