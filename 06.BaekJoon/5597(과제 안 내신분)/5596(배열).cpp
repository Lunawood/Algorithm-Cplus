#include <stdio.h>

bool ab[201];
int x;

int main(void){
	for(int i = 0; i < 28; i++){
		scanf("%d", &x);
		ab[x] = true;
	}	
	for(int i = 1; i < 31; i++){
		if(ab[i] == false){
			printf("%d\n", i);
		}
	}
	return 0;
}
