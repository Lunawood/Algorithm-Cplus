#include <iostream>
#include <queue>

using namespace std;

int n, m, x, idx;
int cnt = 0;
int main(void){
	cin >> n;	// n : ť�� ũ�� 
	int a[n];	// ť 
	int b[n];	// �ӽ� ���� 
	for(int i = 1; i <= n; i++){
		a[i-1] = i;
	}
	cin >> m;
	while(m--){
		cin >> x;
		// ��ġ Ž�� 
		for(int i = 0; i < n; i++){
			if(a[i] == x){
				idx = i;
			}
		}
		
		int middle = (n-1)/2 + (n-1)%1;
		
		// �ű��	
		for(int i = 0; i < n; i++){
			if(i-idx < 0) b[n+i-idx-1] = a[i];
			else b[i-idx-1] = a[i];
		}
		
		// �ű� ��ŭ ���� ���� 
		if(idx <= middle){	 // �������� �� ĭ �̵���Ų��.
			cnt += idx;
		} else {	// ���������� �� ĭ �̵���Ų��. 
			cnt += n-idx; 
		}
		
		// ť�� �ٽ� �ű�
		for(int i = 0; i < n; i++){
			a[i] = b[i];
		}
		n -= 1; 
	}
	
	cout << cnt << endl;

	return 0;
}
