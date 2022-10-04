#include<stdio.h>

// �������� �Ǻ��ϴ� ��� �����佺�׳׽��� ü�� ���
 
int number = 100000;
int a[100001];

void primeNumberSieve(){
	// �ʱ�ȭ 
	for(int i = 2; i <= number; i++){
		a[i] = i;
	}
	// Ư�� ������� ����� 
	for(int i = 2; i <= number; i++){
		// ������ ������ �ǳʶٱ� 
		if(a[i] == 0) continue;
		// �ƴϸ� ������� �������� 
		for(int j = i + i; j <= number; j += i){
			a[j] = 0;
		}
	}
	// �Ҽ��� ���
	for(int i = 2; i<= number; i++){
		if(a[i] != 0) printf("%d", a[i]);
	}
}

int main(void){
	primeNumberSieve();
}
