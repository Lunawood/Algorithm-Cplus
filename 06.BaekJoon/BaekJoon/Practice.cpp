#include <iostream>
using namespace std;

long long int A[200001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, num = 0;
	cin >> N >> M;
	
	long long int a, b;
	for(int i = 0; i < N; i++){
		cin >> a;
		A[a]++;
	} 
	for(int i = 0; i < M; i++){
		cin >> b;
		A[b]++;
	} 	
	
	// O(n)
	for(int i = 0; i < 200001; i++){
		if(A[i] == 1){
			num++;
		}
	}
	
	cout << num << endl;
	
	return 0;
}
