#include<stdio.h>
#include<cmath>
// 점을 포함하는 원의 개수
 
int n, xs, ys, xd, yd, c, r, cx, cy; 
// 점을 포함하는 원 체크  
bool check(int x, int y){
	return pow(x-cx, 2) + pow(y-cy, 2) <= pow(r,2);
} 

int main(void){
	scanf("%d", &n);
	int cnt[n] = {0,};
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &xs, &ys, &xd, &yd);
		scanf("%d", &c);
		for(int j = 0; j < c; j++){
			scanf("%d %d %d", &cx, &cy, &r);
			// 출발점은 포함하면서, 도착점은 포함하지 않는원 
			if(check(xs, ys) and !check(xd, yd)){
				cnt[i]++;
			}
			// 도착점은 포함하면서, 출발점은 포함하지 않는원 
			if(!check(xs, ys) and check(xd, yd)){
				cnt[i]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d\n", cnt[i]);
	}
	return 0;
}

