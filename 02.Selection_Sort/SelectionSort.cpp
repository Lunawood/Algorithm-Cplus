#include <stdio.h>
#include <iostream>
using namespace std;

// 선택 정렬 : Selection Sort
// 시간 복잡도 	: N * (N + 1) / 2
//				: O(N^2)
// 비효율적인 알고리즘... 
int main(void) {
	// min : 최솟값 선택 
	int i, j, min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 10; i++){
		// 최소값 임의 지정 (원소들보다 커야함) 
		min = 9999;
		// 정해진 앞의 원소는 읽을 필요x, start = i 
		for(j = i; j < 10; j++) {
			// 원소의 값이 min보다 작은 경우 
			if(min > array[j]){
				// 가장 작은 원소 값 저장 
				min = array[j];
				// 가장 작은 원소 값 위치 저장 
				index = j;
			}
		}	
		// 읽은 원소 중 맨 앞 원소와 가장 작은 원소 스와핑 
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;	
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

