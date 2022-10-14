#include <iostream>
#include <map>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> A;
	map<int, int> B;
	
	int a, b;
	int M, N;
	
	cin >> M >> N;
	
	for(int i = 0; i < M; i++){
		cin >> a;
		A.insert(pair<int, int>(a, 1));
	}
	
	for(int t = 0; t < N; t++){
		cin >> b;
		// 교집합 찾기 
		if(A.find(b) != A.end()){
			B.insert(pair<int, int>(b, 1));
		}
	}
	
	cout << M + N - 2*B.size();
	
	return 0;
}
