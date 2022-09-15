#include <stdio.h>

int sorted[1000001];

void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	
	// 두개의 집합 중 작은 것 순으로 정렬하여 넣음 
	while(i <= middle && j <= n){
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	
	// 나머지 집합에 남은 원소들 넣기(정렬되어 있음)
 	if(i > middle){	// j집합인 남았을 때 
 		for(j; j <= n; j++){
 			sorted[k] = a[j];
 			k++;
		} 
 	} else {
 		for(i; i <= middle; i++){
 			sorted[k] = a[i];
 			k++;
		 }
	}
	
	// 정렬된 배열들 넣기
	for(int t = m; t <= n; t++){
		a[t] = sorted[t];
	} 
}

// 재귀함수 
void mergeSort(int a[], int m, int n){
	if(m < n){	// 원소가 1개 이상인 경우
		int middle = (m + n) / 2; 
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
} 

int main(void){
	int number;
	scanf("%d", &number);
	
	int array[number];
	
	for(int i = 0; i < number; i++){
		scanf("%d", &array[i]);
	}
	
	mergeSort(array, 0, number - 1);
	
	for(int i = 0; i < number; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
