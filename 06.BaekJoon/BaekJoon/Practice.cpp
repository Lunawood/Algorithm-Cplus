#include<iostream>

using namespace std;

int num[100001];

int main(void){
	int N, M, result;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> num[i];
	}
	for(int i = 1; i <= M; i++){
		result = 0;
		int s, e;
		cin >> s >> e;
		for(int k = s; k <= e; k++){
			result += num[k];
		}
		cout << result << endl;
	}
}
