#include<stdio.h>
#include<cmath>
// ���� �����ϴ� ���� ����
 
int n, xs, ys, xd, yd, c, r, cx, cy; 
// ���� �����ϴ� �� üũ  
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
			// ������� �����ϸ鼭, �������� �������� �ʴ¿� 
			if(check(xs, ys) and !check(xd, yd)){
				cnt[i]++;
			}
			// �������� �����ϸ鼭, ������� �������� �ʴ¿� 
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

