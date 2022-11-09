#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, result = 0; 
vector<int> d;
vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

void dp(){
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			if(v[j].second < v[i].second){
				d[i] = max(d[i], d[j] + 1);
			}
		}
		result = max(result, d[i]);
	}
	cout << N - result << endl;
}

int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		pair<int, int> c = make_pair(x, y);
		v.push_back(c);
		d.push_back(1);
	}
	
	dp();
	
	return 0;
}
