#include<iostream>
#include<vector>
using namespace std;

// DFS 깊이 우선 탐색 
int number = 7;
int c[7];
vector<int> a[8];

// stack 대신 재귀함수를 사용 (컴퓨터 기본구조 stackframe) 
void dfs(int x) {
	if(c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		dfs(y);
	}
}

void element() {
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
}

int main(void){
	element();
	
	dfs(1);
	
	return 0;	
}
