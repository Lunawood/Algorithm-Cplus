#include<stdio.h>
// 버블 정렬(Bubble Sort)

int main(void ){
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 10; i++){
		// 한바퀴를 돌때마다. 가장 큰 수가 맨 뒤에 정렬이 된다.
		// 따라서 다음 for문은 1씩 감소한다. 
		for(j = 0; j < 9 - i; j++){
			if(array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
}
