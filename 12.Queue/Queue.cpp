#include<iostream>
#include<queue>
using namespace std;

int main(void){
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();	// 7이 나감
	q.push(6); 
	q.pop();	// 5가 나감
	
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	} 
	
	return 0;
}
