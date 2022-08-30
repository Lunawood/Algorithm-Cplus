#include <stdio.h>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp))
#define Size 10

// �������� O(N^2)
// ���������� �̵��ϸ鼭 ������ ���Ұ� ������ �ִ� ���ҵ�
// ���̿� ���Ե�.
// O(N^2)�� ���ĵ� �� ���� ȿ���� ����. ������� ���ĵ� ���Ҵ� �н���. (2,3,1 -> 1�� ������.) 

// 3 2 1 / 3 <- 2 1 / 2 3 1
// 2 3 1 / 2 3 <- 1 / 2 1 3
// 2 1 3 / 2 <- 1 3 / 1 2 3
void insertion_sort(int array[], int n) {
	int i, j, temp;
	
	// �������� �ڵ����� ���ĵ�. 
	for(i = 0; i < n-1; i++){
		// ������� �ϳ��� ���Ҹ� ���´�. 
		j = i;
		// ���� ������ ������ Ŭ������ SWAP�� �����Ѵ�. 
		while(array[j] > array[j + 1]){
			SWAP(array[j], array[j + 1], temp);
			j--;
		}
	}
}

int main(void) {
	int n = Size;
	int array[n] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	// �������� ���� 
	insertion_sort(array, n);
	
	// ���� ��� ���
	for(int i = 0; i < n; i++){
		printf("%d ", array[i]);
	} 
	return 0;
} 
