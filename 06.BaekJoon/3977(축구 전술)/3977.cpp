#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define MAX 100001
using namespace std;

int v, e, id;				// 노드수, 간선수, 고유번호 
vector<int> a[MAX];			// 간선정보 
int d[MAX];					// 노드 방문여부 
vector<vector<int> > SCC;	// SCC 집합 
bool finished[MAX];			// 노드 처리여부 
stack<int> s;				// SCC 노드 
bool inDegree[MAX];			// SCC 진입차수 
int group[MAX];				// SCC group번호 지정 
vector<int> result;			// 진입차수가 0인 SCC 노드

int dfs(int x){
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y));
		else if(!finished[y]) parent = min(parent, d[y]);
	}
	
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			group[t] = SCC.size(); 
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	
	return parent;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		id = 0;
		SCC.clear();
		result.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(inDegree, inDegree + MAX, false);
		fill(group, group + MAX, 0);
		 
		scanf("%d %d", &v, &e);
		for(int i = 0; i < v; i++){
			a[i].clear();
		}
		
		for(int i = 0; i < e; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		
		// SCC Strongly Connected Component
		for(int i = 0; i < v; i++){
			if(d[i] == 0) dfs(i);
		}
		
		// SCC 위상정렬 
		for(int i = 0; i < v; i++){
			for(int j = 0; j < a[i].size(); j++){
				int y = a[i][j];
				if(group[i] != group[y]) inDegree[group[y]] = true;
			}
		}
		
		// 진입차수가 0인 SCC 저장 
		int cnt = 0;
		for(int i = 0; i < SCC.size(); i++){
			if(!inDegree[i]){
				cnt++;
				for(int j = 0; j < SCC[i].size(); j++){
					result.push_back(SCC[i][j]);
				}
			}
		}
		
		sort(result.begin(), result.end());
		
		// 출력
		if(cnt != 1){
			printf("Confused\n\n");
		} else {
			for(int i = 0; i < result.size(); i++){
				printf("%d\n", result[i]);
			}
			printf("\n");
		}
	} 
	return 0;
}
