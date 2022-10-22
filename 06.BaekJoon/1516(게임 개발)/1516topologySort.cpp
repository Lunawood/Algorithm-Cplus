#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001

using namespace std;

class Edge {
public:
	int node, time;
	Edge(int node, int time){
		this->node = node;
		this->time = time;
	}
};

int start, finish;
int n, inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort(){
	queue<int> q;
	// 시작점 노드를 큐에 삽입합니다. 
//	for(int i = 1; i <= n; i++){
//		if(inDegree[i] == 0){
//			queue.push(i);
//		}
//	}
	q.push(start);
	// 더이상 방문할 노드가 없을 때까지 
	while(!q.empty()){
		int x = queue.front();
		queue.pop();
		for(int i = 0; i < a[x].size(); i++){
			Edge y = a[x][i];
			if(--inDegree[y] == 0){
				queue.push(y);
			}
		}
	}
}

int main(){
	
	
	return 0;
}
