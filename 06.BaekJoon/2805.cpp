#include <iostream>
using namespace std;

int n, m, cnt;
int s, middle, f;

int main(void){
	scanf("%d %d", &n, &m);
	
	int a[n];
	int mymax;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mymax = max(mymax, a[i]);
	}
	
	s = 0;
	f = mymax;
	
	while(s <= f){
		middle = (s + f) / 2;
		
		long long int len = 0;
		
		for(unsigned int i = 0; i < n; i++){
			if(a[i] > middle){
				len += (a[i] - middle);
			}
		}
		
		if(m <= len){
			s = middle + 1;
			cnt = middle;
		} else {
			f = middle - 1;
		}
	}
	
	printf("%d", cnt);
		
	return 0;
}
