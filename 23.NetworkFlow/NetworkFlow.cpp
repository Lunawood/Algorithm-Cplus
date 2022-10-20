#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
#define INF 1000000000

using namespace std;

// NetworkFlow : Ư���� �������� �ٸ� ��������
//				�����Ͱ� �󸶳� ���� �帣�� �ִ°� �����ϴ� �˰��� 
// 				��, �ִ� �����͸� �����ϴ� �˰��� 
// ex) ����ü��, ��Ʈ��ũ ������ ���� � ���

// BFS[�ʺ�켱Ž��]�� ��� : Queue�� �̿��ϴ� �˰��� 

int n = 6, result; 						// n: ������ ����, result: ���[�ִ�����]
int c[MAX][MAX], f[MAX][MAX], d[MAX]; 	// c[capacity]:�뷮
										// f[flow]:����, d: �湮����
vector<int> a[MAX];						// ����� ������ ǥ�� 

// start -> end
void maxFlow(int start, int end){
	while(1){
		// fill�Լ��� � ���Ӽ��� �� �ڷᱸ��(���ͳ� �迭 ����)��
		// ���������� ���ӵ� ������ � ���̳� ��ü�� ��� �����ϰ� ���� �� 
		// ����ϴ� �Լ��̴�.
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i = 0; i < a[x].size(); i++){
				int y = a[x][i];
				// �湮���� ���� ��� �߿��� �뷮�� ���� ���
				// ��, �带 �� �ִ� ��� and �湮���� ���� ��� 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1){
					q.push(y);
					d[y] = x;	// ��θ� ����մϴ�. 
					if(y == end) break;	// �������� ������ �� ���. 
				} 
			}
		}
		// ��� ��θ� �� ã�� �ڿ� Ż���մϴ�. 
		if(d[end] == -1) break;
		int flow = INF;
		// �Ųٷ� �ּ� ���� Ž���մϴ�. 
		for(int i = end; i != start; i = d[i]){
			flow = min(flow, c[d[i]][i] - f[d[i]][i]); 
		}
		// �ּ� ������ŭ �߰��մϴ�. 
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
