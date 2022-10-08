#include<stdio.h>

int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화합니다.
// 이어진 노드는 숫자로 표기, 이어지지 않은 노는 무한으로 표 
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

// 방문 여부 
bool v[6];
// 최단 거리 저장 
int d[6];

// 가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex(){
	int min = INF;
	int index = 0;
	// 선형 탐색  : 6개 모두 확인해본다. 
	for(int i = 0; i < number; i++){
		if(d[i] < min && !v[i]){
			min = d[i];
			index = i;
		}
	} 
	return index;
} 

// 다익스트라를 수행하는 함수
void dijkstra(int start){
	// 각각의 노드와의 거리 입력 및 방문표시 
	for(int i = 0; i < number; i++){
		d[i] = a[start][i];
	}
	v[start] = true;
	
	for(int i = 0; i < number - 2; i++){
		int current = getSmallIndex();
		v[current] = true;
		for(int j = 0; j < 6; j++){
			if(!v[j]){
				if(d[current] + a[current][j] < d[j]){
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
} 

int main(void){
	dijkstra(0);
	// 노드 1에서부터 각각의 노드의 최단 거리 
	for(int i = 0; i < number; i++){
		printf("%d ", d[i]);
	}
	
}
