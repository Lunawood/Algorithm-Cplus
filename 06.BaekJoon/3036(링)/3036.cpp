#include<iostream>
#include<vector>
using namespace std;

vector<int> v, g;

// 최대공약수
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
} 

int main(void){
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		v.push_back(x);
	} 
	
	for(int i = 1; i < v.size(); i++){
		g.push_back(gcd(v[0], v[i]));
	}
	
	for(int i = 0; i < g.size(); i++){
		cout << v[0] / g[i] << "/" << v[i+1]/g[i] << '\n';
	}
	
	return 0;
}
