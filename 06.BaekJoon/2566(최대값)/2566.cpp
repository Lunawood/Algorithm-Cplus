#include <stdio.h>

int x, max = -1, col, row;

int main(void){
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			scanf("%d", &x);
			if(max < x){
				row = i;
				col = j;
				max = x;
			}
		}
	}
	
	printf("%d\n%d %d", max, row, col);
	return 0;
}
