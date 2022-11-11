#include <iostream>
#include <vector>
#include <stack> 
#define MAX 10001 // 총 노드의 개수 
using namespace std; 
// Strongly Connected Component = SCC
// 강한 결합 요소 : 강하게 결합된 정점 집합 서로 긴밀하게 연결되어 있음.
// 같은 SCC에 속하는 두 정점은 서로 도달이 가능하다. 

// 코사라주 알고리즘, 타잔 알고리즘
// 타잔 알고리즘 : 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘

int id, d[MAX];			// id는 각 노드의 고유번호, d는 방문여부 
bool finished[MAX];		// 각각의 노드의 처리여부 
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

// DFS는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x){
	d[x] = ++id;		// 노드마다 고유한 번호 할당 
	s.push(x);			// 스택에 자기 자신을 삽입합니다.
	
	int parent = d[x];	// 처음에는 자기자신이 부모가 됨. 
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		// 방문하지 않은 이웃 
		if(d[y] == 0) parent = min(parent, dfs(y));
		// 방문은 했지만 아직 처리되지 않은 노드 
		else if(!finished[y]) parent = min(parent, d[y]);
	}
	
	// 부모가 자기자신인 경우 
	if(parent == d[x]) {
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc); 
	} 
	
	
	// 자신의 부모 값을 반환합니다.
	return parent; 
} 

int main(void){
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for(int i = 1; i <= v; i++){
		if(d[i] == 0) dfs(i);
	}
	printf("SCC의 갯수 : %d\n", SCC.size());
	for(int i = 0; i < SCC.size(); i++){
		printf("%d번째 SCC: ", i + 1);
		for(int j = 0; j < SCC[i].size(); j++){
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}
