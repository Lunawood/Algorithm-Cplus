#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 너비 우선 탐색 Breath First Search (BFS)
// 특정 데이터를 탐색할때 너비를 우선으로 탐색
// 최단길이를 보장해야할 때 많이 사용
// ex) 네비게이션, 미로...
 
int number = 7;
int c[7];	// 방문 처리 checked
vector<int> a[8]; 	// 각 Node의 index가 1~7

void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;	// 방문처리
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);						// 1. 1이 출력 
		for(int i = 0; i < a[x].size(); i++){	// 2. vector[1]에 들어있는 2, 3이 for문으로 돌아감 
			int y = a[x][i];					// 3. y 에 2부터 대입 
			if(!c[y]){							// 4. 배열 c[2]방문 확인 
				q.push(y);						// 5. queue에 2 넣기 
				c[y] = true;					// 6. 배열 c[2]방문 처리 
			}
		}
	}
} 
// 벡터는 가변처리 할 수 있어 메모리를 효율적으로 사용 가능
// 배열	0 1 2 3 4 5 6 7
//   	  2 3 1 2 2 3 3
//   	  3 4 7 5 4 7 6
void element() {
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
}
int main(void){
	element();
	
	bfs(1);
	
	return 0;
}
