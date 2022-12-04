#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int n,m;
int s, middle, f;
int x;

void binarySearch(int s, int middle, int f){
	if(a[middle] == x) {
		printf("%d\n", 1);
		return;
	}
	if(s + 1 == f){
		if(a[s] == x or a[f] == x){
			printf("%d\n", 1);
			return;
		} else {
			printf("%d\n", 0);
			return;
		}
	}
	if(a[middle] < x){
		s = middle;
		binarySearch(s, (s + f) / 2, f);
	}
	if(a[middle] > x){
		f = middle;
		binarySearch(s, (s + f) / 2, f);
	}
} 

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	sort(a, a + n);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		binarySearch(0, (n - 1) / 2, n - 1);
	}
	return 0;
}
