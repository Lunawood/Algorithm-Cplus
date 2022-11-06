#include<stdio.h>

int n, x, y, v;
bool board[101][101]; 

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		for(int j = y; j <= y + 9; j++){
			for(int k = x; k <= x + 9; k++){
				board[j][k] = true;
			}
		}
	}
	
	for(int j = 1; j <= 100; j++){
		for(int k = 1; k <= 100; k++){
			if(board[j][k] == true){
				v++;
			}
		}
	}
	
	printf("%d", v);
	return 0;
} 
