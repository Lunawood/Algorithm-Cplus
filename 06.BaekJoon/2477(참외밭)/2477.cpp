#include <iostream>
using namespace std;

// 6������ �������� �׾� ū �簢������ ���� �簢���� ���� ���̸� ���� 

int main(void){
	int K, area = 0;	// ������ ����, ū �簢���� ���� 
	int p;
	int d[6][2];	// ���� �Է� 
	
	// ���� ��1, ��2, ��3, ��4
	// �Է�
	cin >> K;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 2; j++){
			cin >> d[i][j];
		}
	}
	
	for(int i = 0; i < 6; i++){
		int cmp = d[i][1] * d[(i + 1) % 6][1];
		if(area < cmp){
			area = cmp;
			p = i;
		}
	}
	area -= d[(p + 3) % 6][1] * d[(p + 4) % 6][1];
	// ��� ��� 
	cout << area * K<< "\n";
	
	return 0; 
}
