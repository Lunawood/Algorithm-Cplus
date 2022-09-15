#include <stdio.h>

// CounterSort 계수 정렬
// 조건이 있는 정렬인 경우 '계수 정렬"을 사용하면 가장 빠르다
// 원소를 각각 세서 저장 
int main(void){
	int temp;
	int count[5];
	int array[30] = {
		1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
		3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
		3, 1, 4, 3, 5, 1, 2, 1, 1, 1
	};
	// count 배열 0으로 초기화 
	for(int i = 0; i < 5; i++){
		count[i] = 0;
	}
	// 원소에 맞는 배열에 증감 
	for(int i = 0; i < 30; i++){
		count[array[i] - 1]++;
	}
	//
	for(int i = 0; i < 5; i++){
		if(count[i] != 0){
			for(int j = 0; j < count[i]; j++){
				printf("%d", i + 1);
			}
		}
	}
	return 0;
}
