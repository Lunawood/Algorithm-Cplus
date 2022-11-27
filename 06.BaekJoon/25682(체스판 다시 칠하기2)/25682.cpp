#include <iostream>
#include <vector>
using namespace std;

// mxn보드 kxk체스판
int m, n, k;
char x;
int mx, my;
// 2차원 벡터 보드(색깔) 
vector<vector<char> > v;
// 보드(숫자) 
vector<int> d;
vector<vector<int> > c;
// 각각의 합
int tot[2001][2001];
 
// 1. 변을 공유하는 사각형의 색깔이 다른 사각형들의 숫자
// char to int
void ctoi(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0){
				if(j == 0){
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
				} else if(j == m-1) {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
				} else {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
				}
			} else if(i == n-1){
				if(j == 0){
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				} else if(j == m-1) {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				} else {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				}
			} else {
				if(j == 0){
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				} else if(j == m-1) {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				} else {
					c[i][j] += (v[i][j] != v[i][j-1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i][j+1]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i+1][j]) ? 1 : 0;
					c[i][j] += (v[i][j] != v[i-1][j]) ? 1 : 0;
				}
			}
		}
	}
}

// 2. 누적함이 가장 큰 kxk 를 찾아라. 
void total() {
	// 초기화 왼쪽상단을 0,0으로 잡았을때의 합
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			tot[0][0] += c[i][j];
		}
	}
	for(int i = 0; i <= n - k; i++){
		for(int j = 0; j <= m - k; j++){
			// 첫번째 줄에서만 자신의 왼쪽부분을 더하고 뺀다. 
			if(i==0 and j != 0){
				tot[i][j] = tot[i][j-1]; 
				for(int y = 0; y < k; y++){
					tot[i][j] -= c[y][j-1];
					tot[i][j] += c[y][j+k-1];
				}
			} 
			// 두번째 줄부터는 위의 합을 더하고 뺀다.
			if(i != 0) {	 
				tot[i][j] = tot[i-1][j];
				for(int x = 0; x < k; x++){
					tot[i][j] -= c[i-1][j+x];
					tot[i][j] += c[i+k-1][j+x];
				}
			}
		}
	}
	
	int mymax = 0; 
	// 각각의 합의 최대값의 좌표 찾기 
	for(int i = 0; i <= n - k; i++){
		for(int j = 0; j <= m - k; j++){
			if(mymax < tot[i][j]){
				mymax = tot[i][j];
				mx = j;
				my = i;
			}
		}
	}
}

// 3. kxk의 최대값의 첫번째 좌표
void cstand() {
	
	for(int i = my; i < my + k; i++){
		for(int j = mx; j < mx + k; j++){
			if()
		}
	} 
}

 
int main(void){
	cin >> n >> m >> k;	// m이 가로 n이 세로
	
	// nxm보드 입력 
	for(int i = 0; i < n; i++){
		vector<char> w;
		for(int j = 0; j < m; j++){
			cin >> x;
			w.push_back(x);
		}
		v.push_back(w);
	}
	
	// 2차원 벡터 0으로 초기화 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			d.push_back(0);
		}
		c.push_back(d);
	}
	
	ctoi();
	
	total();
	
	cout << mx << " " <<my << endl;
	
	for(int i = my; i < my + k; i++){
		for(int j = mx; j < mx + k; j++){
			cout << c[i][j] << " ";
		}cout << endl;
	} 
	return 0;
}
