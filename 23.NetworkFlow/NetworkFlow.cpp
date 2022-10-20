#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
#define INF 1000000000

using namespace std;

// NetworkFlow : 특정한 지점에서 다른 지점으로
//				데이터가 얼마나 많이 흐르고 있는가 측정하는 알고리즘 
// 				즉, 최대 데이터를 측정하는 알고리즘 
// ex) 교통체증, 네트워크 데이터 전송 등에 사용

// BFS[너비우선탐색]를 사용 : Queue를 이용하는 알고리즘 

int n = 6, result; 						// n: 정점의 개수, result: 결과[최대유량]
int c[MAX][MAX], f[MAX][MAX], d[MAX]; 	// c[capacity]:용량
										// f[flow]:유량, d: 방문여부
vector<int> a[MAX];						// 연결된 간선을 표현 

// start -> end
void maxFlow(int start, int end){
	while(1){
		// fill함수는 어떤 연속성을 띈 자료구조(벡터나 배열 같은)의
		// 시작점부터 연속된 범위를 어떤 값이나 객체로 모두 지정하고 싶을 때 
		// 사용하는 함수이다.
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i = 0; i < a[x].size(); i++){
				int y = a[x][i];
				// 방문하지 않은 노드 중에서 용량이 남은 경우
				// 즉, 흐를 수 있는 경우 and 방문하지 않은 경우 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1){
					q.push(y);
					d[y] = x;	// 경로를 기억합니다. 
					if(y == end) break;	// 도착지에 도달을 한 경우. 
				} 
			}
		}
		// 모든 경로를 다 찾은 뒤에 탈출합니다. 
		if(d[end] == -1) break;
		int flow = INF;
		// 거꾸로 최소 유량 탐색합니다. 
		for(int i = end; i != start; i = d[i]){
			flow = min(flow, c[d[i]][i] - f[d[i]][i]); 
		}
		// 최소 유량만큼 추가합니다. 
		for(int i = end; i != start; i = d[i]){
			f[d[i]][i] += flow; 
			f[i][d[i]] -= flow;
		}
		result += flow;
	}

}

void setting(){
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;
	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;
	a[4].push_back(2);
	a[2].push_back(4);
	c[4][2] = 3;
	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;
	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;
	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;
	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;
	a[3].push_back(5);
	a[5].push_back(3);
	c[3][5] = 3;
	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;
	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;
}

int main(void){
	setting();
	
	maxFlow(1, 6);
	printf("%d", result);
	return 0;
}
