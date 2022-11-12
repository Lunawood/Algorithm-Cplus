#include<iostream>
#include<stack>
#include<vector> 
#define MAX 100001
using namespace std;

// SCC�׷��� �ϳ��� ���ȭ�Ͽ� �������ķ� ���������� 0�� �׷���� ���ϱ� 

int id, N, M, T;			// ���̵� 
int d[MAX];					// �湮���� 
bool finished[MAX];			// ó������ 
int group[MAX];				// ���������� �ϱ����� SCC�׷� 
bool inDegree[MAX];			// �������� 
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
 
int dfs(int x){
	d[x] = ++id;		// �湮���� �� ���� ID�� �Է� 
	s.push(x);
	
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		// �湮X
		if(d[y] == 0) parent = min(parent, dfs(y));
		// �湮O but ó��X 
		else if(!finished[y]) parent = min(parent, d[y]);
	}	
	
	// �θ�� ���� ��� �� �θ� ��带 ã�� ��� 
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
		// �׽�Ʈ ���۽� �ʱ�ȭ
		id = 0;
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(group, group + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		// ���� ���� ���� �Է� 
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++){	// �������� �ʱ�ȭ
			a[i].clear(); 
			
		}
		// ���� ���� �Է� 
		for(int i = 0; i < M; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		
		// ��� ���� SCC�� �Է� 
		for(int i = 1; i <= N; i++){
			if(d[i] == 0) dfs(i);
		}
		
		// �������ķ� Ȯ�� 
		for(int i = 1; i <= N; i++){
			for(int j = 0; j < a[i].size(); j++){
				int y = a[i][j];	// y : ����Ǿ� �ִ� ���� 
				// �׷��� ���� �ٸ��ٴ� ���� �ٸ� �׷�� ����Ǿ� �ִٴ� ��.
				// �� �������� ���� �ʾƵ� �ٸ� �׷쿡 ����Ǿ� �Ѿ. 
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
