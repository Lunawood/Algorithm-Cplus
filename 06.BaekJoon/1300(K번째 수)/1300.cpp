#include <iostream>
using namespace std;

long long n, k;
long long s, m, f;

int main(void){
	scanf("%d %d", &n, &k);
	
	s = 1;
	f = n*n;
	
	while(s <= f){
		m = (s + f) / 2;
		long long cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += min(m/i, n);
		}
		
		if(cnt >= k){
			f = m - 1;
		} else {
			s = m + 1;
		}
	}
	
	printf("%d\n", s);
	return 0;
}
