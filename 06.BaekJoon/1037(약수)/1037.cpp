#include <iostream>
#include <algorithm>

using namespace std;

// 가장 작은 약수와 가장 큰 약수를 곱하면됨

int main(void){
	int N;
	cin >> N;
	int a[N];	
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	sort(a, a + N);
	
	cout << a[0] * a[N-1] << endl;
	return 0;
}
