#include <stdio.h>
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
// 퀵 정렬 평균 O(N * logN), 최악 사간 복잡도는 O(N^2) => 정렬이 되어있는 경우 제일 느림...
// 재귀함수를 사용. 
int N = 10;
int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

// 포인터는 일반 변수처럼 선언해야한다. 
void quickSort(int *array, int start, int end){
	if(start >= end) {	// 부분집합에서 원소가 1개인 경우. 
		return;
	}
	
	int key = start;	// key는 첫번째 원소
	int i = start + 1; 	// 큰값을 찾는 idx
	int j = end; 		// 작은값을 찾는 idx 
	int temp;
	 
	while(i <= j){		// 엇갈릴때까지 반복 
		while(array[i] <= array[key]){	// 키 값보다 큰값을 만날때까지 
			i++;
		}
		while(array[j] >= array[key] && j > start){	// 키 값보다 작은값을 만날때까지
			j--; 
		}
		if(i > j) {	// 현재 엇갈린 상태면 키 값과 교체 
			SWAP(array[key], array[j], temp);
		}
		else {	// 엇갈리지 않으면 j와 i를 교체
			SWAP(array[i], array[j], temp); 
		} 
	} 
	
	quickSort(array, start, j - 1);
	quickSort(array, j + 1, end);
}

int main() {
	quickSort(array, 0, N - 1);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
