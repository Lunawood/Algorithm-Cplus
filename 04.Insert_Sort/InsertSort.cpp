#include <stdio.h>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp))
#define Size 10

// 삽입정렬 O(N^2)
// 오른쪽으로 이동하면서 각각의 원소가 왼쪽의 있는 원소들
// 사이에 삽입됨.
// O(N^2)인 정렬들 중 가장 효율이 좋음. 어느정도 정렬된 원소는 패스함. (2,3,1 -> 1만 움직임.) 

// 3 2 1 / 3 <- 2 1 / 2 3 1
// 2 3 1 / 2 3 <- 1 / 2 1 3
// 2 1 3 / 2 <- 1 3 / 1 2 3
void insertion_sort(int array[], int n) {
	int i, j, temp;
	
	// 마지막은 자동으로 정렬됨. 
	for(i = 0; i < n-1; i++){
		// 순서대로 하나씩 원소를 집는다. 
		j = i;
		// 집은 원소의 왼쪽이 클때만다 SWAP을 실행한다. 
		while(array[j] > array[j + 1]){
			SWAP(array[j], array[j + 1], temp);
			j--;
		}
	}
}

int main(void) {
	int n = Size;
	int array[n] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	// 삽입정렬 수행 
	insertion_sort(array, n);
	
	// 정렬 결과 출력
	for(int i = 0; i < n; i++){
		printf("%d ", array[i]);
	} 
	return 0;
} 
