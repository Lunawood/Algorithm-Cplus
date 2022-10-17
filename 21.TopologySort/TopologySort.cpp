#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

// 위상정렬 :  
// 순서가 정해져있는 작업을 차례대로 수행할때,  그 순서를 결정해주기 위해 사용하는
// 알고리즘.
// 일렬로 그래프를 나열할 수 있도록 함 
// DAG(Directed Acyclic Graph) : 방향이 있고 사이클이 없는 그래프에 사용 가능
// -> 시작점이 필요하기 때문.
// 특징 1. 현재 그래프는 위사정렬이 가능한지
// 2. 위상정렬이 가능하면 그 결과를 보여줌.
// O(V+E) [V : vertex 정점, E : edge 간선]

// 알고리즘 : 진입차수가 0인 정점을 큐에 삽입
// 삽입된 정점의 간선들을 모두 제거.
// 반복...

// inDegree : 각 노드의 진입차수 갯수. 
int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort(){
	int result[MAX];
	queue<int> q;
	// 진입차수가 0인 노드를 큐에 삽입합니다.
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0) q.push(i);
	} 
	// 위상정렬이 완전히 수행되려면 정확히 N개의 노드를 방문합니다.
	 for(int i = 1; i <= n; i++){
	 	// n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것.
		if(q.empty()){
			printf("사이클이 발생했습니다.");
			return;
		} 
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
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

int main(void){
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	
	topologySort();
	
	return 0;
}
