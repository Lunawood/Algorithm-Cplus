#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 
#include <sstream>
#include <stdlib.h> 
#include <queue>
using namespace std;

string InttoString[100001];
vector<pair<string, int> > StringtoInt;

// 이진 탐색 
int binarySearch(string tmp, int s, int e){
	int m = (s + e) / 2;
	if(s > e) return 0;
	else {
		if(StringtoInt[m].first == tmp) {
			return StringtoInt[m].second;
		}
		else if(StringtoInt[m].first < tmp) return binarySearch(tmp, m + 1, e);
		else return binarySearch(tmp, s, m - 1);
	}
}

int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);	//없으면 시간 초과
    
	int N, M, tot = 0;
	string tmp;
	queue<string> q;
	cin >> N >> M;
	for(int i = 1; i < N + 1; i++){
		cin >> tmp;
		InttoString[i] = tmp;	// 숫자->문자, 배열 
		StringtoInt.push_back(make_pair(tmp, i));	// 문자->숫자, vector 
	}
	
	// 문자 정렬 : 이진 검색을 사용하기 위해서... 
	sort(StringtoInt.begin(), StringtoInt.end());

	for(int i = 0; i < M; i++){
		cin >> tmp;
		int n;
		// 문자와 숫자 구분 
		if((int)isdigit(tmp.at(0))) {	// 숫자 -> 글자 
			n = atoi(&tmp.at(0));
			q.push(InttoString[n]);
		} else {	// 글자 -> 숫자 
			stringstream ss;
			ss << binarySearch(tmp, 0, N);
			q.push(ss.str());
		}
	}
	
	// 출력 
	while(q.size()){
		cout << q.front() << endl;
		q.pop();
	}
	
	return 0;
}

