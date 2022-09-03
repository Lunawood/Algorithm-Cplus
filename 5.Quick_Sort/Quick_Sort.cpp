#include <stdio.h>
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
// �� ���� ��� O(N * logN), �־� �簣 ���⵵�� O(N^2) => ������ �Ǿ��ִ� ��� ���� ����...
// ����Լ��� ���. 
int N = 10;
int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

// �����ʹ� �Ϲ� ����ó�� �����ؾ��Ѵ�. 
void quickSort(int *array, int start, int end){
	if(start >= end) {	// �κ����տ��� ���Ұ� 1���� ���. 
		return;
	}
	
	int key = start;	// key�� ù��° ����
	int i = start + 1; 	// ū���� ã�� idx
	int j = end; 		// �������� ã�� idx 
	int temp;
	 
	while(i <= j){		// ������������ �ݺ� 
		while(array[i] <= array[key]){	// Ű ������ ū���� ���������� 
			i++;
		}
		while(array[j] >= array[key] && j > start){	// Ű ������ �������� ����������
			j--; 
		}
		if(i > j) {	// ���� ������ ���¸� Ű ���� ��ü 
			SWAP(array[key], array[j], temp);
		}
		else {	// �������� ������ j�� i�� ��ü
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
