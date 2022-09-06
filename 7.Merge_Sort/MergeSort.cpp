#include <stdio.h>

// 병합 정렬 NlogN 보장 but 추가적인 데이터 공간 필요.
// 모든 배열들을 나누어 2의 지수만큼 합쳐서 정렬(2 -> 4 -> 8 ...)
 
int sorted[1000001];		// 정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	
	// 작은 순서대로 배열에 삽입
	while(i <= middle && j <= n){
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		}
		else{
			sorted[k] = a[j];
			j++;
		}
		k++;
	} 
	
	// 남은 데이터도 삽입
	if(i > middle){
		for(int t = j; t <= n; t++){
			sorted[k] = a[t];
			k++;
		}
	} else {
		for (int t = i; t <= middle; t++){
			sorted[k] = a[t];
			k++;
		}
	}
	
	// 정렬된 배열을 삽입
	for(int t = m; t <= n; t++) {
		a[t] = sorted[t];
	} 
} 

void mergeSort(int a[], int m, int n){
	// 크기가 1보다 큰 경우
	if(m < n){
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
	
	mergeSort(array, 0 , number - 1);
	
	for(int i = 0; i < number; i++){
		printf("%d\n", array[i]);
		
	}
	return 0;
}
