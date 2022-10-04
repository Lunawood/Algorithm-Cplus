#include<stdio.h>
#include<math.h>

// 소수를 판별하는 알고리즘
// 2부터 자기자신-1 까지 나눠봄 
// 시간복잡도 O(N) 
bool isPrimeNumber1(int x){
	for(int i = 2; i < x; i++){
		if(x % i == 0) return false;
	}
	return true;
} 

// 2부터 자신의 제곱근까지 나눠봄
// 시간복잡도 O(N/2) 
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
