#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

// Value to Key 
string poketmonNtoS[100001];
// map 선언: key(string), value(int)
map<string, int> poketmonStoN;
  
int main(){
	// cin, cout 입출력 속도 가속
	// 1. scanf, prinf를 섞어서 사용x
	// 2. 싱글 쓰레드 환경에서만 사용할 것
	// endl보다 \n을 사용하는 것이 빠르다. 
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// N: 정보 입력 갯수, M: 문제 입력 갯수 
	int N, M;
	cin >> N >> M;
	
	string info;
	for(int i = 0; i < N; i++){
		cin >> info;
		poketmonNtoS[i + 1] = info;
		poketmonStoN.insert(make_pair(info, i + 1)); 
	}

	string problem;
	for(int i = 0; i < M; i++){
		cin >> problem;
		
		if(0 < isdigit(problem[0]) and isdigit(problem[0]) < 10){
			cout << poketmonNtoS[stoi(problem)] << "\n";
		} else {
			auto item = poketmonStoN.find(problem);
			cout << item->second << "\n";
		}
	}
	
	return 0;
}
