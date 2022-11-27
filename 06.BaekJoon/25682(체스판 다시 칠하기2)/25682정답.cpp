#include <iostream>
#include <vector>
#define MAX 3000
using namespace std;

int n, m, k;
char v[MAX][MAX];
int value[MAX][MAX];

// 누적합 
int twoDsum(char color){
	int cnt = 1000000000;
	
	fill(&value[0][0], &value[MAX-1][MAX-1], 0);
	// char -> int 다르면 1 같으면 0 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			if((i+j)%2==0 && v[i][j] != color){
				value[i + 1][j + 1] = 1;
			}
			if((i+j)%2==1 && v[i][j] == color) {
				value[i + 1][j + 1] = 1;
			}
			// 2차원 누적합 
			value[i + 1][j + 1] = value[i + 1][j] + value[i][j + 1] - value[i][j] + value[i + 1][j + 1];
		}
	}
	for(int i = 1; i < n - k + 2; i++){
		for(int j = 1; j < m - k + 2; j++){
			cnt = min(cnt, value[i+k-1][j+k-1] - value[i+k-1][j-1] - value[i-1][j+k-1] + value[i-1][j-1]);
		}
	}
	return cnt;
}

int main(void){
	cin >> n >> m >> k;
	// 입력 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> v[i][j];
		}
	}
	
	cout << min(twoDsum('B'), twoDsum('W')) << endl;
	return 0;
}
