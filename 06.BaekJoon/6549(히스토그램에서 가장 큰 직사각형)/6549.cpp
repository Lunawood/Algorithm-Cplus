#include <iostream>
#include <algorithm>
#define MAX 2000000000 
using namespace std;

long long n;		// n: 사각형의 개수, idx: 최솟값의 index 
long long h[100001];	// 히스토그램 저장 
long long ans;		// 가장 큰 사각형  
long long seg[1000001];

// 분할정복으로 찾고 segment tree로 구간별 저장
int minStorage(int node, int s, int e){
	if(s==e) return seg[node] = s; // 최솟값이 아닌 인덱스값을 입력 
	int m = (s+e)/2;
	int left = minStorage(2*node, s, m);
	int right = minStorage(2*node+1, m+1, e);
	return seg[node] = h[left] < h[right] ? left : right;
}

// 구간에서 최솟값을 출력 SegmentTree O(nlogn)
int query(int node, int s, int e, int l, int r){
	if(e < l or r < s) return MAX;
	if(s >= l and e <= r) return seg[node];
	int m = (s+e)/2;
	int left = query(2*node, s, m, l, r);
	int right = query(2*node+1, m+1, e, l, r);
	
	// 메모리초과 원인
	if(left == MAX) return right;
	else if(right == MAX) return left; 
	else return h[left] < h[right] ? left : right;
}

// 분할정복 
void binaryFunc(long long s, long long e){
	if(s > e) return;
	
	long long idx = query(1, 0, n-1, s, e);
	ans = max(ans, (e - s + 1) * h[idx]); 
	// 왼쪽 
	binaryFunc(s, idx - 1);
	// 오른쪽
	binaryFunc(idx + 1, e);
}

int main(void){
	while(true){
		ans = 0;
		cin >> n;
		if(n == 0) break;
		
		for(int i = 0; i < n; i++){
			cin >> h[i];
		}
		
		// 분할정복으로 찾고 segment tree로 구간별 저장
		minStorage(1, 0, n-1);		
		
		// 분할 정복
		binaryFunc(0, n - 1);
		
		cout << ans << endl;
	}
	
	return 0;
}
