#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#define MAX 100001
using namespace std;

int d[MAX];	// 방문 여부
bool finished[MAX];	// 완전한 처리 
vector<vector<int> > SCC; 
vector<int> a[MAX];	// 간선 정보 (ex. 1->3 연결)
stack<int> s; 
int id;	// 고유번호 (번호가 작을수록 그룹의 부모)
 
int dfs(int x){
	d[x] = ++id;// 고유번호 입력 및 방문처리
	s.push(x);	// 스택
	
	int parent = d[x];	// parent : 그룹의 부모 
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		// 방문하지 않았을 경우
		if(d[y] == 0) parent = min(parent, dfs(y));
		// 방문한 경우 ->  완전히 처리가 되지 않은 경우 
		else if(!finished[y]) parent = min(parent, d[y]);
	} 
	
	// x가 그룹의 부모인 경우 
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;	// 그룹의 부모에서 완전히 처리 
			if(t == x) break;	// 부모까지 나오면 반복문 끝 
		}
		sort(scc.begin(), scc.end());	// 노드 오름차순 정리 
		SCC.push_back(scc);
	}
	
	return parent;
} 

int main(void){
	int v, e;
	// 입력 
	scanf("%d %d", &v, &e); 
	for(int i = 0; i < e; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		a[A].push_back(B);		
	}
	// SCC 각각의 노드 입력 
	for(int i = 1; i <= v; i++){
		if(d[i] == 0) dfs(i);
	}
	// 정리
	sort(SCC.begin(), SCC.end());
	
	// 출력
	printf("%d\n", SCC.size());
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			printf("%d ", SCC[i][j]);
		}
		printf("%d\n", -1);
	} 
	return 0;
}
