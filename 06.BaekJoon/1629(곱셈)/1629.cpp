#include <iostream>
using namespace std;

int a, b, c;

long long int func(int x){
	if(x == 1) return a % c;
	
	long long int k = func(x/2) % c;
	
	if(x%2 == 0) return k*k%c;
	else return k*k%c*a%c;
}
 
int main(void){
	scanf("%d %d %d", &a, &b, &c);
	
	
	printf("%lld\n", func(b));
	
	return 0;
}
