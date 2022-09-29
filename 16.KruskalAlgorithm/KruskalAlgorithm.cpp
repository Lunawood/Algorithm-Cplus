#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 크루스칼 알고리즘 : 	가장 적은 비용(간선)으로 
//						모든 노드를 연결하기 위해 사용하는 알고리즘
// ex) 여러개의 도시가 있을 때 각 도시를 도로를 이용해 연결하고자할 때

// 원리 : 간선을 거리가 짧은 순으로 그래프에 포함 

// Union-Find 함수 : '사이클이 발생하는지 검사'로 사용 
// 부모 노드를 찾는 함수
int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}
// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}
// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	return 0;
} 

// 간선 클래스 선언
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	// 간선비용을 오름차순으로 정렬 
	bool operator <(Edge &edge){
		return this->distance < edge.distance;
	}
}; 
// 데이터 입력 
vector<Edge> v;

void Data(){
	
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));	
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
}

int main(void){
	int n = 7;
	int m = 11;
	
	Data();
	
	// 간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	// 각 정점이 포함된 그래프가 어디인지 저장(Union-Find 초기값)
	int parent[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
	} 
	
	int sum = 0;
	for(int i = 0; i < v.size(); i++){
		// 사이클이 발생하지 않는 경우 그래프에 포함
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);

	return 0;
}
