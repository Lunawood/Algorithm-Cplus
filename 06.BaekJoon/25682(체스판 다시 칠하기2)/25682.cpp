#include <iostream>
#include <vector>
using namespace std;

// mxn���� kxkü����
int m, n, k;
char x;
int mx, my;
// 2���� ���� ����(����) 
vector<vector<char> > v;
// ����(����) 
vector<int> d;
vector<vector<int> > c;
// ������ ��
int tot[2001][2001];
 
// 1. ���� �����ϴ� �簢���� ������ �ٸ� �簢������ ����
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

// 2. �������� ���� ū kxk �� ã�ƶ�. 
void total() {
	// �ʱ�ȭ ���ʻ���� 0,0���� ��������� ��
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			tot[0][0] += c[i][j];
		}
	}
	for(int i = 0; i <= n - k; i++){
		for(int j = 0; j <= m - k; j++){
			// ù��° �ٿ����� �ڽ��� ���ʺκ��� ���ϰ� ����. 
			if(i==0 and j != 0){
				tot[i][j] = tot[i][j-1]; 
				for(int y = 0; y < k; y++){
					tot[i][j] -= c[y][j-1];
					tot[i][j] += c[y][j+k-1];
				}
			} 
			// �ι�° �ٺ��ʹ� ���� ���� ���ϰ� ����.
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
	// ������ ���� �ִ밪�� ��ǥ ã�� 
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

// 3. kxk�� �ִ밪�� ù��° ��ǥ
void cstand() {
	
	for(int i = my; i < my + k; i++){
		for(int j = mx; j < mx + k; j++){
			if()
		}
	} 
}

 
int main(void){
	cin >> n >> m >> k;	// m�� ���� n�� ����
	
	// nxm���� �Է� 
	for(int i = 0; i < n; i++){
		vector<char> w;
		for(int j = 0; j < m; j++){
			cin >> x;
			w.push_back(x);
		}
		v.push_back(w);
	}
	
	// 2���� ���� 0���� �ʱ�ȭ 
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
