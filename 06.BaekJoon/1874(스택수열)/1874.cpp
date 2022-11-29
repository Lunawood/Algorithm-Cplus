#include<iostream>
#include<stack>
#include<vector>
#define MAX 100001
using namespace std;

stack<int> s;
vector<char> t;
int n, cnt = 1;

int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		while(cnt <= x){
			s.push(cnt);
			cnt++;
			t.push_back('+');
		}
		if(s.top() == x){
			s.pop();
			t.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
	}
	
	for(int i = 0; i < t.size(); i++){
		cout << t[i] << '\n';
	}
	
	return 0;
}
