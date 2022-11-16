#include <iostream>
using namespace std;

// x!�� 2�� 5�� ���� ���ϴ� �Լ� 
long long func(int n, int x){
	int num = 0;
	for(long long i = x; n / i >= 1; i*=x){
		num += n / i;
	}
	
	return num;
}

int main(void){
	int n, m;
	long long t, f;
	
	scanf("%d %d", &n, &m);
	
	t = func(n, 5) - func(m, 5) - func(n-m, 5);
	f = func(n, 2) - func(m, 2) - func(n-m, 2);
	
	printf("%d\n", min(t, f));	
	
	return 0;
} 
