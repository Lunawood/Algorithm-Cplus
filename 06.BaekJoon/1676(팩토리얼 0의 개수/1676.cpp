#include <iostream>
using namespace std;

int a, result;
// 5�� ������ ���� �ȴ� 
int main(void){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x = i;
		while(x%5==0) {
			x/=5;
			a++;
		} 
	}
	
	cout << a;
	return 0;
}
