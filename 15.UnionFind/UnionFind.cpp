#include <stdio.h>
using namespace std;

// Union-Find : 크루스칼 알고리즘에 활용된다. 

// 부모 노드를 찾는 함수
// 자기자신을 부모로 삼는 원소를 만날때까지 진행 
int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수 
// parent: 원소들이 담겨 있는 배열
// a, b : 합치려는 원소들 
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b; 
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	return 0;
} 
int main(void){
	int parent[11];
	for(int i = 1; i <= 10; i++){
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	
	// 연결한 경우 : 1, 연결이 안되어 있는 경우 : 0 
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 8);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	
	return 0;
}
