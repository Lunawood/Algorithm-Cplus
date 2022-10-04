#include<stdio.h>

// 여러개를 판별하는 경우 에라토스테네스의 체를 사용
 
int number = 100000;
int a[100001];

void primeNumberSieve(){
	// 초기화 
	for(int i = 2; i <= number; i++){
		a[i] = i;
	}
	// 특정 배수들을 지우기 
	for(int i = 2; i <= number; i++){
		// 지워져 있으면 건너뛰기 
		if(a[i] == 0) continue;
		// 아니면 배수부터 지워가기 
		for(int j = i + i; j <= number; j += i){
			a[j] = 0;
		}
	}
	// 소수만 출력
	for(int i = 2; i<= number; i++){
		if(a[i] != 0) printf("%d", a[i]);
	}
}

int main(void){
	primeNumberSieve();
}
