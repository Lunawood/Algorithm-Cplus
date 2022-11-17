#include <iostream>

using namespace std;

// 이항계수1	
void cal(int n, int k){
	int result = 1;
	int div = 1; 
	for(int i = 0; i < k; i++){
		result *= (n - i);
		div *= (i + 1);
	}
	printf("%d", result/div);
} 

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	cal(n, k);
	return 0;
}
