#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

vector<int> v;
int gcd;
vector<int> result;

// �ִ�����
int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a%b);
} 

int main(){
	int m;
	cin >> m;
	while(m--){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	gcd = v[1] - v[0];
	
	// ������ ���� �ִ������� ���Ѵ�. 
	for(int i = 2; i < v.size(); i++){
		gcd = GCD(gcd, v[i]-v[i-1]);
	}
	
	// �ִ������� ����� ���Ѵ�.
	for(int i = 2; i * i <= gcd; i++){
		if(gcd % i == 0){
			result.push_back(i);
			result.push_back(gcd/i);
		}
	} 
	result.push_back(gcd);
	sort(result.begin(), result.end());
	// �ߺ� ���� 
	result.erase(unique(result.begin(), result.end()), result.end());
	for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
	return 0;
}
