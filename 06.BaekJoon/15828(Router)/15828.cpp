#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int n;

int main(void){
	cin >> n;
	while(1){
		int x;
		cin >> x;
		if(x == -1) break;
		if(x == 0){
			if(!q.empty()) q.pop();
		} else {
			if(q.size() < n) q.push(x);
		}
	}
	
	if(q.empty()){
		cout << "empty" << endl;
	} else {
		while(!q.empty()){
			cout << q.front() << " ";
			q.pop();
		}
	}
}
