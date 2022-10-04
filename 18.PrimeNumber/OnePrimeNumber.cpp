#include<stdio.h>
#include<math.h>

// �Ҽ��� �Ǻ��ϴ� �˰���
// 2���� �ڱ��ڽ�-1 ���� ������ 
// �ð����⵵ O(N) 
bool isPrimeNumber1(int x){
	for(int i = 2; i < x; i++){
		if(x % i == 0) return false;
	}
	return true;
} 

// 2���� �ڽ��� �����ٱ��� ������
// �ð����⵵ O(N/2) 
bool isPrimeNumber2(int x){
	int end = (int) sqrt(x);
	for(int i = 2; i <= end; i++){
		if(x % i == 0) return false;
	}
	return true;
}

int main(void){
	printf("%d", isPrimeNumber1(100));
	printf("%d", isPrimeNumber2(100));
	return 0;
}
