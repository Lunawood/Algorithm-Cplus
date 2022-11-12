#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define MAX 100001
using namespace std;

int v, e;
vector<int> a[MAX];
int d[MAX];
int id;
vector<vector<int> > SCC;
bool finished[MAX];
stack<int> s;
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
			if(t == x) break;
		}
		sort(scc.begin(), scc.end());
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
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		
		scanf("%d %d", &v, &e);
		for(int i = 0; i < v; i++){
			a[i].clear();
		}
		
		for(int i = 0; i < e; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		
		for(int i = 0; i < v; i++){
			if(d[i] == 0) dfs(i);
		}
		int result = 0;
		for(int i = 0; i < SCC.size(); i++){
			if(SCC[i].size() != 1) {
				result++;
				for(int j = 0; j < SCC[i].size(); j++){
					printf("%d\n", SCC[i][j]);
				}
				printf("\n");
			}
		}
		if(result == 0) printf("Confused\n\n");
	} 
	
	return 0;
}
