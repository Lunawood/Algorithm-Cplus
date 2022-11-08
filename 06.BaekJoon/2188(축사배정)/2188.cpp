#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

// �̺� ��Ī 2188 ������ ���� 

vector<int> a[MAX];
int d[MAX];
bool c[MAX];	// Ȯ���� �� ��������� �迭

// ��Ī�� ������ ��� True, ������ ��� False 
bool dfs(int x){
	// ����� ��� ��忡 ���ؼ� �� �� �ִ��� �õ�
	for(int i = 0; i < a[x].size(); i++){
		int t = a[x][i];
		// �̹� ó���� ���� �� �̻� �� �ʿ䰡 ����
		if(c[t]) continue; 
		c[t] = true;
		// ����ְų� ���� ��忡 �� �� ������ �ִ� ��� ��
		// ����ְų� �ٸ� ��尡 �� �ٸ� ������ �� ������ �ִ� ���  
		if(d[t] == 0 || dfs(d[t])){
			d[t] = x;
			return true; 
		} 
	} 
	return false;
}

int main(void){
	int n, m, s;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &s);
		for(int j = 1; j <= s; j++){
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		// �ִ��� ��� �ֽ��ϴ�.
		fill(c, c + MAX, false); 
		if(dfs(i)) count++;	// ��� ������ �Ǹ� count���� ������Ų��. 
	}
	printf("%d\n", count); 
	return 0;
} 
