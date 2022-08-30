#include <stdio.h>
#include <iostream>
using namespace std;

// ���� ���� : Selection Sort
// �ð� ���⵵ 	: N * (N + 1) / 2
//				: O(N^2)
// ��ȿ������ �˰���... 
int main(void) {
	// min : �ּڰ� ���� 
	int i, j, min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 10; i++){
		// �ּҰ� ���� ���� (���ҵ麸�� Ŀ����) 
		min = 9999;
		// ������ ���� ���Ҵ� ���� �ʿ�x, start = i 
		for(j = i; j < 10; j++) {
			// ������ ���� min���� ���� ��� 
			if(min > array[j]){
				// ���� ���� ���� �� ���� 
				min = array[j];
				// ���� ���� ���� �� ��ġ ���� 
				index = j;
			}
		}	
		// ���� ���� �� �� �� ���ҿ� ���� ���� ���� ������ 
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;	
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

