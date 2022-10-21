#include <iostream>
using namespace std;

// 6각형에 보조선을 그어 큰 사각형에서 작은 사각형을 빼서 넓이를 구함 

int main(void){
	int K, area = 0;	// 참외의 개수, 큰 사각형의 넓이 
	int p;
	int d[6][2];	// 길이 입력 
	
	// 연산 동1, 서2, 남3, 북4
	// 입력
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
	// 결과 출력 
	cout << area * K<< "\n";
	
	return 0; 
}
