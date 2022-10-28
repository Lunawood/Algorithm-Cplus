#include <iostream>
#include <vector>
using namespace std;

int sudo[10][10]; // ������ ������
vector<int> pos[2]; // ���ڸ� ��ġ 
int cnt = 0;

bool found = false; // ������ �� �ϼ� �÷���

// ���ڸ��� �������� ������ Ȯ��
bool Rowsearch(int x, int y){
	// 1~9���� ���� Ȯ�� 
	for(int j = 1; j <= 9; j++){
		if(sudo[y][j] == sudo[y][x] && j != x){
			return false;
		}
	}
	return true;
} 

// ���ڸ��� �������� ������ Ȯ��
bool Colsearch(int x, int y){
	// 1~9���� ���� Ȯ�� 
	for(int i = 1; i <= 9; i++){
		if(sudo[i][x] == sudo[y][x] && i != y){
			return false;
		}
	}
	return true;
}

// ���ڸ��� �������� �ڽ� Ȯ��
bool Boxsearch(int x, int y){
	int bx, by;	// 5, 2
	bx = (x - 1)/3; // 1
	by = (y - 1)/3; // 0
	// 1~9���� ���� Ȯ��
	for(int i = by * 3 + 1; i <= by * 3 + 3; i++){
		for(int j = bx * 3 + 1; j <= bx * 3 + 3; j++){
			if(sudo[i][j] == sudo[y][x]){
				if(j != x && i != y){
					return false;	
				}
			}
		}
	}
	return true;
} 

bool check(int x, int y){
	if(!Rowsearch(x, y) or !Colsearch(x, y) or !Boxsearch(x, y)){
		return false;
	}
	return true;
}

void sudoku(int N){
	if(N == cnt){
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++){
				cout << sudo[i][j] << " ";
			}
			cout << endl;
		}
		// ��� �� �ٽ� ȸ�Ϳ� ���� �ʵ���...
		found = true;
		return;
	}
	// 1���� 9���� �ϳ��� �־��
	for(int i = 1; i <= 9; i++){
		sudo[pos[0][N]][pos[1][N]] = i;
		if(check(pos[1][N], pos[0][N])) {
			sudoku(N + 1);
		}
		if(found){
			return;
		}
	} 
	// ������ ã�� ���� ���
	sudo[pos[0][N]][pos[1][N]] = 0;
	return;
}

int main(void){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cin >> sudo[i][j];
			if(sudo[i][j]==0){
				cnt++;					// ��ĭ ���� 
				pos[0].push_back(i);	// y�� ��ǥ 
				pos[1].push_back(j);	// x�� ��ǥ 
			}
		}
	}
	
	sudoku(0);
	
	return 0;
}

