#include<iostream>
#include<stack>
#include<vector> 
#define MAX 100001
using namespace std;

// SCC그룹을 하나의 노드화하여 위상정렬로 진입차수가 0인 그룹들을 구하기 

int id, N, M, T;			// 아이디값 
int d[MAX];					// 방문여부 
bool finished[MAX];			// 처리여부 
int group[MAX];				// 위상정렬을 하기위한 SCC그룹 
bool inDegree[MAX];			// 진입차수 
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
 
int dfs(int x){
	d[x] = ++id;		// 방문여부 및 고유 ID값 입력 
	s.push(x);
	
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		// 방문X
		if(d[y] == 0) parent = min(parent, dfs(y));
		// 방문O but 처리X 
		else if(!finished[y]) parent = min(parent, d[y]);
	}	
	
	// 부모와 같은 경우 즉 부모 노드를 찾은 경우 
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			finished[t] = true;
			group[t] = SCC.size() + 1; 
			scc.push_back(t);
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	
	return parent;
}

int main(void){
	scanf("%d", &T);
	while(T--){
		// 테스트 시작시 초기화
		id = 0;
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(group, group + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		// 노드와 간선 개수 입력 
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++){	// 간선정보 초기화
			a[i].clear(); 
			
		}
		// 간선 정보 입력 
		for(int i = 0; i < M; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		
		// 노드 정보 SCC에 입력 
		for(int i = 1; i <= N; i++){
			if(d[i] == 0) dfs(i);
		}
		
		// 위상정렬로 확인 
		for(int i = 1; i <= N; i++){
			for(int j = 0; j < a[i].size(); j++){
				int y = a[i][j];	// y : 연결되어 있는 노드들 
				// 그룹이 서로 다르다는 것은 다른 그룹과 연결되어 있다는 것.
				// 즉 수동으로 밀지 않아도 다른 그룹에 연결되어 넘어감. 
				if(group[i] != group[y]) inDegree[group[y]] = true;
			}
		}
		int result = 0;
		for(int i = 1; i <= SCC.size(); i++){
			if(!inDegree[i]) result++;
		} 
		printf("%d\n", result);
	}
	return 0;
}
