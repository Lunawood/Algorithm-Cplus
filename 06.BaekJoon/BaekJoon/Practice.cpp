#include <iostream>
#include <string> 
#include <set>

// 11478 서로 다른 부분 문자열의 개수 : 집합을 활용하여 중복을 제거하는 문제 
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<string> se;
	string s;
	cin >> s;
	
	// 문자열의 길이가 홀수이면 +1, 짝수이면 +0. 
	int len = s.length();
	
	for(int i = 1; i <= len; i++){	// 부분집합의 길이 
		// abc -> len = 3
		// (0, 1), (1, 1), (2, 1)
		// (0, 2), (1, 2)
		// (0, 3)
		for(int j = 0; j <= len - i; j++){
			string p = s.substr(j, i);
			// set에 없으면 추가 
			se.insert(p);
		}
	}
	cout << se.size() << endl;
	return 0;
}
