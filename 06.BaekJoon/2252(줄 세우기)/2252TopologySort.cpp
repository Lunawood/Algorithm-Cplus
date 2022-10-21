#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

// 위상 정렬 기초 문제풀이
// 위상 정렬: 순서가 정해져 잇는 작업이 여러 개 나열이 되어 있을 때
// 				이들의 순서를 정확히 결정해주는 알고리즘. 

int n, inDegree[MAX], result[MAX];	// 각 정점의 진입차수, 출력결과 
vector<int> a[MAX];	// 정점과 간선 표현

void topologySort() {
	queue<int> q;
	// 진입차수가 0인 정점을 큐에 삽입합니다.
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	// 정렬이  완전히 수행되려면 정확히 n개의 노드를 방문합니다. 
	for(int i = 1; i <= n; i++){
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int j = 0; j < a[x].size(); j++){
			int y = a[x][j];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다. 
			if(--inDegree[y] == 0){
				q.push(y);
			} 
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", result[i]);
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++;
	}
	
	topologySort();
	
	return 0;
} 
