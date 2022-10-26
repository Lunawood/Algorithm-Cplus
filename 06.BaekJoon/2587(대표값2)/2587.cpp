#include<iostream>
#include<algorithm>

using namespace std;

int tot = 0, mid, a[5], x; 

int main(void){
	for(int i = 0; i < 5; i++){
		cin >> x;
		a[i] = x;
		tot += x;
	}
	
	sort(a, a+5);
	
	cout << tot/5 << endl << a[2];
	return 0;
}
