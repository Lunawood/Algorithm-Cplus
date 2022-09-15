#include <stdio.h>

int sorted[1000001];

void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	
	// �ΰ��� ���� �� ���� �� ������ �����Ͽ� ���� 
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
	
	// ������ ���տ� ���� ���ҵ� �ֱ�(���ĵǾ� ����)
 	if(i > middle){	// j������ ������ �� 
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
	
	// ���ĵ� �迭�� �ֱ�
	for(int t = m; t <= n; t++){
		a[t] = sorted[t];
	} 
}

// ����Լ� 
void mergeSort(int a[], int m, int n){
	if(m < n){	// ���Ұ� 1�� �̻��� ���
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
