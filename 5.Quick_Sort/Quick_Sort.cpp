#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x) (x) = (y) (y) = (temp))
#define Max 10
// �� ���� N * logN
// ����Լ��� ���. 

int N = 10;
int array[10] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};

// �����ʹ� �Ϲ� ����ó�� �����ؾ��Ѵ�. 
void quickSort(int *array){
	for(int i = 0; i< 10; i++){
		printf("%d ", array[i]);
	}
}

int main() {
	quickSort(array);
		
	return 0;
}
