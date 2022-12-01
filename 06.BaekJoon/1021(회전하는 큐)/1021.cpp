#include <iostream>
#include <queue>

using namespace std;

int n, m, x, idx;
int cnt = 0;
int main(void){
	cin >> n;	// n : 큐의 크기 
	int a[n];	// 큐 
	int b[n];	// 임시 저장 
	for(int i = 1; i <= n; i++){
		a[i-1] = i;
	}
	cin >> m;
	while(m--){
		cin >> x;
		// 위치 탐색 
		for(int i = 0; i < n; i++){
			if(a[i] == x){
				idx = i;
			}
		}
		
		int middle = (n-1)/2 + (n-1)%1;
		
		// 옮기기	
		for(int i = 0; i < n; i++){
			if(i-idx < 0) b[n+i-idx-1] = a[i];
			else b[i-idx-1] = a[i];
		}
		
		// 옮긴 만큼 갯수 세기 
		if(idx <= middle){	 // 왼쪽으로 한 칸 이동시킨다.
			cnt += idx;
		} else {	// 오른쪽으로 한 칸 이동시킨다. 
			cnt += n-idx; 
		}
		
		// 큐로 다시 옮김
		for(int i = 0; i < n; i++){
			a[i] = b[i];
		}
		n -= 1; 
	}
	
	cout << cnt << endl;

	return 0;
}
