#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#define MAX 100001
using namespace std;

int d[MAX];	// �湮 ����
bool finished[MAX];	// ������ ó�� 
vector<vector<int> > SCC; 
vector<int> a[MAX];	// ���� ���� (ex. 1->3 ����)
stack<int> s; 
int id;	// ������ȣ (��ȣ�� �������� �׷��� �θ�)
 
int dfs(int x){
	d[x] = ++id;// ������ȣ �Է� �� �湮ó��
	s.push(x);	// ����
	
	int parent = d[x];	// parent : �׷��� �θ� 
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		// �湮���� �ʾ��� ���
		if(d[y] == 0) parent = min(parent, dfs(y));
		// �湮�� ��� ->  ������ ó���� ���� ���� ��� 
		else if(!finished[y]) parent = min(parent, d[y]);
	} 
	
	// x�� �׷��� �θ��� ��� 
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;	// �׷��� �θ𿡼� ������ ó�� 
			if(t == x) break;	// �θ���� ������ �ݺ��� �� 
		}
		sort(scc.begin(), scc.end());	// ��� �������� ���� 
		SCC.push_back(scc);
	}
	
	return parent;
} 

int main(void){
	int v, e;
	// �Է� 
	scanf("%d %d", &v, &e); 
	for(int i = 0; i < e; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		a[A].push_back(B);		
	}
	// SCC ������ ��� �Է� 
	for(int i = 1; i <= v; i++){
		if(d[i] == 0) dfs(i);
	}
	// ����
	sort(SCC.begin(), SCC.end());
	
	// ���
	printf("%d\n", SCC.size());
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			printf("%d ", SCC[i][j]);
		}
		printf("%d\n", -1);
	} 
	return 0;
}
