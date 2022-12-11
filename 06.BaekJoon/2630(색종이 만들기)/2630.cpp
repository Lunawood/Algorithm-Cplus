#include <iostream>

using namespace std;

int n;
int z = 0, o = 0;
int arr[200][200];

void tree(int x, int y, int t){
	
	bool Zero = false, One = false;
	
	for(int i = y; i < y+t; i++){
		for(int j = x; j < x+t; j++){
			if(arr[i][j] == 0){
				Zero = true;
			} else One = true;
			
			if(Zero and One) break;
		}
	}
	if(Zero and One){
		tree(x, y, t / 2);
		tree(x, y + t/2, t/2);
		tree(x + t/2, y, t/2);
		tree(x + t/2, y + t/2, t/2);
	}
	if(!Zero){
		o++;
		return;
	}
	if(!One){
		z++;
		return;
	}
}
	
int main(void){
	// 색종이 길이 입력 
	scanf("%d", &n);
	
	// 색종이 입력 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	tree(1, 1, n);
	
	printf("%d\n%d", z, o);
	return 0;
} 
