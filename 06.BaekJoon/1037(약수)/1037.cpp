#include <iostream>
#include <algorithm>

using namespace std;

// ���� ���� ����� ���� ū ����� ���ϸ��

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
