#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x) (x) = (y) (y) = (temp))
#define Max 10
// 퀵 정렬 N * logN
// 재귀함수를 사용. 

int N = 10;
int array[10] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};

// 포인터는 일반 변수처럼 선언해야한다. 
void quickSort(int *array){
	for(int i = 0; i< 10; i++){
		printf("%d ", array[i]);
	}
}

int main() {
	quickSort(array);
		
	return 0;
}
