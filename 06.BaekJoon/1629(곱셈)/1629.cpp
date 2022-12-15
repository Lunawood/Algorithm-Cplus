#include <iostream>
using namespace std;

int a, b, c;

int func(int x){
	if(x == 1) return a % c;
	
	int k = func(x/2) % c;
	
	if(x%2 == 0) return k*k%c;
	else return k*k%c*a%c;
}
 
int main(void){
	scanf("%d %d %d", &a, &b, &c);
	
	
	printf("%d\n", func(b));
	
	return 0;
}
