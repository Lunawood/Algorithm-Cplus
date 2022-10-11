#include <iostream>
using namespace std;
 
// �÷��̵� �ͼ�(Floyd Warshall) �˰�����
// '�������'���� '��� ����'������ �ִ� ��θ� ���ϴ� �˰����� 
// �������α׷����� Ȱ��(DP), �ð����⵵ : O(N^3) 

// ���ͽ�Ʈ�� : �� ������������ �ٸ� ������ �ִ� ��θ� ���ϴ� �˰�����.
// 				-> ���� ������ �迭�� ����Ѵ�. 
// �÷��̵� �ͼ� �˰����� : �� ������������ �ٸ� �������� �ִ� ��θ� ���ϴ� �˰�����
//				-> ���� ������ �迭�� ����Ѵ�.
 
int number = 4;
int INF = 1000000000;

// �ڷ� �迭�� �ʱ�ȭ�մϴ�.
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0},
};

void floydWarshall(){
	// ��� �׷����� �ʱ�ȭ�մϴ�. 2���� �迭 a���� 2���� �迭 d�� ���� 
	int d[number][number];
	// ���� 
	for(int i = 0; i< number; i++){
		for(int j = 0; j < number; j++){
			d[i][j] = a[i][j];
		}
	}
	
	// k = ���İ��� ���
	for(int k = 0; k < number; k++){
		// i = ��� ���
		for(int i = 0; i< number; i++){
			// j = ���� ���
			for(int j = 0; j < number; j++){
				if(d[i][k] + d[k][j] < d[i][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			} 
		} 
	} 
	
	// ����� ����մϴ�.
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