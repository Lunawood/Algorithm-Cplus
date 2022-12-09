#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int n, c;
long long int mymin = 1000000000, mymax;
// 1 2   4       8 9
// 1 2 3 4 5 6 7 8 9
int main(void){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	// 집들의 사이 최대 거리와 최소 거리를 저장 
	for(int i = 0; i < n - 1; i ++){
		mymin = min(mymin, v[i+1] - v[i]);
		mymax = max(mymax, v[i+1] - v[i]);
	}
	
	return 0;
}
