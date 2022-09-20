#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// �ʺ� �켱 Ž�� Breath First Search (BFS)
// Ư�� �����͸� Ž���Ҷ� �ʺ� �켱���� Ž��
// �ִܱ��̸� �����ؾ��� �� ���� ���
// ex) �׺���̼�, �̷�...
 
int number = 7;
int c[7];	// �湮 ó�� checked
vector<int> a[8]; 	// �� Node�� index�� 1~7

void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;	// �湮ó��
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);						// 1. 1�� ��� 
		for(int i = 0; i < a[x].size(); i++){	// 2. vector[1]�� ����ִ� 2, 3�� for������ ���ư� 
			int y = a[x][i];					// 3. y �� 2���� ���� 
			if(!c[y]){							// 4. �迭 c[2]�湮 Ȯ�� 
				q.push(y);						// 5. queue�� 2 �ֱ� 
				c[y] = true;					// 6. �迭 c[2]�湮 ó�� 
			}
		}
	}
} 
// ���ʹ� ����ó�� �� �� �־� �޸𸮸� ȿ�������� ��� ����
// �迭	0 1 2 3 4 5 6 7
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
