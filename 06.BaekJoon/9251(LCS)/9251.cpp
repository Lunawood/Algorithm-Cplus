#include <iostream>
#define MAX 1001
using namespace std;

// LCS : Longest Common Subsequence 최장 공통 부분 수열
// 2차원 배열로 풀어야한다. 

string a;
string b;
int LCS[MAX][MAX];
int result = 0;

void lcs() {
	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			if(i == 0 or j == 0) LCS[i][j] = 0;
			else if(a[i - 1] == b[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = max(LCS[i - 1][j]N, LCS[i][j - 1]);
			
			result = max(result, LCS[i][j]);
		}
	}
	
	cout << result;
} 

int main(void){
	cin >> a;
	cin >> b;
	
	lcs();
	
	return 0;
}
