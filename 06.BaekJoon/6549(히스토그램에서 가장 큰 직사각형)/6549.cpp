#include <iostream>
#include <algorithm>
#define MAX 2000000000 
using namespace std;

long long n;		// n: �簢���� ����, idx: �ּڰ��� index 
long long h[100001];	// ������׷� ���� 
long long ans;		// ���� ū �簢��  
long long seg[1000001];

// ������������ ã�� segment tree�� ������ ����
int minStorage(int node, int s, int e){
	if(s==e) return seg[node] = s; // �ּڰ��� �ƴ� �ε������� �Է� 
	int m = (s+e)/2;
	int left = minStorage(2*node, s, m);
	int right = minStorage(2*node+1, m+1, e);
	return seg[node] = h[left] < h[right] ? left : right;
}

// �������� �ּڰ��� ��� SegmentTree O(nlogn)
int query(int node, int s, int e, int l, int r){
	if(e < l or r < s) return MAX;
	if(s >= l and e <= r) return seg[node];
	int m = (s+e)/2;
	int left = query(2*node, s, m, l, r);
	int right = query(2*node+1, m+1, e, l, r);
	
	// �޸��ʰ� ����
	if(left == MAX) return right;
	else if(right == MAX) return left; 
	else return h[left] < h[right] ? left : right;
}

// �������� 
void binaryFunc(long long s, long long e){
	if(s > e) return;
	
	long long idx = query(1, 0, n-1, s, e);
	ans = max(ans, (e - s + 1) * h[idx]); 
	// ���� 
	binaryFunc(s, idx - 1);
	// ������
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
		
		// ������������ ã�� segment tree�� ������ ����
		minStorage(1, 0, n-1);		
		
		// ���� ����
		binaryFunc(0, n - 1);
		
		cout << ans << endl;
	}
	
	return 0;
}
