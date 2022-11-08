#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

// 이분 매칭 1671 상어의 저녁식사 

vector<int> a[MAX];
int stat[MAX][3]; 
int d[MAX];
bool c[MAX];	// 확인을 한 노드인지의 배열

// 매칭에 성공한 경우 True, 실패한 경우 False 
bool dfs(int x){
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		if(c[y]) continue;
		c[y] = true;
		if(d[y] == 0 || dfs(d[y])){
			d[y] = x;
			return true;
		}
	} 
	return false;
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a, b, c;
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]){
				a[i].push_back(j);
			} else if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]){
				a[i].push_back(j);
			} else if(stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]){
				a[j].push_back(i);
			}
		}
	}
	int count = 0;
	for(int k = 0; k < 2; k++){
		for(int i = 1; i <= n; i++){
			fill(c, c+MAX, false);
			if(dfs(i)) count++;
		}
	}
	printf("%d\n", n - count);
	return 0;
} 
