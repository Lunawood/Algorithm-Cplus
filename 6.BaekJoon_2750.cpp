#include <stdio.h>
#define SWAP(x, y, temp) (temp = x, x = y, y = temp)
int array[1001];

// Bubble 정렬 
int main(void){
	int number, i, j, min, index, temp;
	// 갯수 입력 
	scanf("%d", &number);
	// 각 원소 입력 
	for(i = 0; i< number; i++){
		scanf("%d", &array[i]);
	}
	
	for(i = 0; i< number; i++){
		min = 1001;
		for(j = i; j < number; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			} 
		}
		SWAP(array[i], array[index], temp);
	}

	for(i = 0; i < number; i++){
		printf("%d ", array[i]);
	}
}
