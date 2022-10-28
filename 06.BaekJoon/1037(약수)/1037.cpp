#include <iostream>
#include <vector>
using namespace std;

int sudo[10][10]; // 스도쿠 보드판
vector<int> pos[2]; // 빈자리 위치 
int cnt = 0;

bool found = false; // 스도쿠 판 완성 플래그

// 빈자리를 기준으로 가로축 확인
bool Rowsearch(int x, int y){
	// 1~9까지 숫자 확인 
	for(int j = 1; j <= 9; j++){
		if(sudo[y][j] == sudo[y][x] && j != x){
			return false;
		}
	}
	return true;
} 

// 빈자리를 기준으로 세로축 확인
bool Colsearch(int x, int y){
	// 1~9까지 숫자 확인 
	for(int i = 1; i <= 9; i++){
		if(sudo[i][x] == sudo[y][x] && i != y){
			return false;
		}
	}
	return true;
}

// 빈자리를 기준으로 박스 확인
bool Boxsearch(int x, int y){
	int bx, by;	// 5, 2
	bx = (x - 1)/3; // 1
	by = (y - 1)/3; // 0
	// 1~9까지 숫자 확인
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
		// 출력 후 다시 회귀에 들어가지 않도록...
		found = true;
		return;
	}
	// 1부터 9까지 하나씩 넣어보기
	for(int i = 1; i <= 9; i++){
		sudo[pos[0][N]][pos[1][N]] = i;
		if(check(pos[1][N], pos[0][N])) {
			sudoku(N + 1);
		}
		if(found){
			return;
		}
	} 
	// 최적을 찾지 못한 경우
	sudo[pos[0][N]][pos[1][N]] = 0;
	return;
}

int main(void){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cin >> sudo[i][j];
			if(sudo[i][j]==0){
				cnt++;					// 빈칸 개수 
				pos[0].push_back(i);	// y축 좌표 
				pos[1].push_back(j);	// x축 좌표 
			}
		}
	}
	
	sudoku(0);
	
	return 0;
}

