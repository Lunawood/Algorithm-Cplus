#include <iostream>
using namespace std;
 
// 플로이드 와샬(Floyd Warshall) 알고리즘
// '모든정점'에서 '모든 정점'으로의 최단 경로를 구하는 알고리즘 
// 동적프로그램밍을 활용(DP), 시간복잡도 : O(N^3) 

// 다익스트라 : 한 정점에서부터 다른 정점의 최단 경로를 구하는 알고리즘.
// 				-> 따라서 일차원 배열을 사용한다. 
// 플로이드 와샬 알고리즘 : 각 정점에서부터 다른 정점들의 최단 경로를 구하는 알고리즘
//				-> 따라서 이차원 배열을 사용한다.
 
int number = 4;
int INF = 1000000000;

// 자료 배열을 초기화합니다.
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0},
};

void floydWarshall(){
	// 결과 그래프를 초기화합니다. 2차원 배열 a에서 2차원 배열 d로 저장 
	int d[number][number];
	// 복사 
	for(int i = 0; i< number; i++){
		for(int j = 0; j < number; j++){
			d[i][j] = a[i][j];
		}
	}
	
	// k = 거쳐가는 노드
	for(int k = 0; k < number; k++){
		// i = 출발 노드
		for(int i = 0; i< number; i++){
			// j = 도착 노드
			for(int j = 0; j < number; j++){
				if(d[i][k] + d[k][j] < d[i][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			} 
		} 
	} 
	
	// 결과를 출력합니다.
	for(int i = 0; i< number; i++){
		for(int j = 0; j < number; j++){
			printf("%d	", d[i][j]);
		}
		printf("\n");
	} 
}

int main(void){
	floydWarshall();
	
	return 0;
}
