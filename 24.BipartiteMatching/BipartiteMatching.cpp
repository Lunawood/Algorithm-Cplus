#include <iostream>
#include <vector>
#define MAX 101
// 이분 매칭 Bipartite Matching
// 두 그룹을 조건에 맞게 매칭을 시키는 것 
// 깊이 우선 탐색(DFS을 이용해 이분 매칭을 푸는 경우 O(V * E)이다. 
using namespace std;

vector<int> a[MAX];
int d[MAX];			// 선택받는 노드 
bool c[MAX];		// 처리여부
int n = 3, m;

// 미칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x){
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
	for(int i = 0; i< a[x].size(); i++){
		int t = a[x][i];
		// 이미 처리한 노드는 더 이상 볼 필요가 없음
		if(c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		 if(d[t] == 0 or dfs(d[t])){
		 	d[t] = x;
		 	return true;
		 }
	} 
	return false;
} 

int main(void){
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for(int i = 0; i <= n; i++){
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	printf("%d개의 매칭이 이루어졌습니다\n", count);
	for(int i = 1; i < MAX; i++){
		if(d[i] != 0){
			printf("%d -> %d\n", d[i], i);
		}
	}
	return 0;
}
