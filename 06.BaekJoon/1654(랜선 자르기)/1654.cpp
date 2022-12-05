#include <iostream>
using namespace std;

unsigned int a[10000];
unsigned int n, k, cnt;


int main(void){
	cin >> k >> n;
	
	unsigned int mymax;
	
	for(int i = 0; i < k; i++){
		cin >> a[i];
		mymax = max(mymax, a[i]);
	}
	
	unsigned int s = 1, f = mymax, m;
	
	while(s <= f){
		m = (s + f) / 2;
		
		unsigned int now = 0;
		
		for(int i = 0; i < k; i++){
			now += a[i] / m;
		}
		
		if(now >= n){
			s = m + 1;
			cnt = max(cnt, m);
		} else {
			f = m - 1;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
