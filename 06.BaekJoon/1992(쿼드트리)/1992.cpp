#include <iostream>
#define MAX 64 
using namespace std;


string a[MAX];

// zero | one
// true | false => print 0
// false | true => print 1
// false | false => recursive 
void recursive(int x, int y, int size) {
	bool zero = true, one = true; 
	// �������� 0�Ǵ� 1�� ���� �����ִ��� �˻� 
	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			if(a[i][j] == '0') one = false;
			else zero = false;
		}
	}
	
	if(zero){
		printf("0");
		return;
	}
	if(one){
		printf("1");
		return;
	}
	
	if(!one and !zero){
		printf("(");
		recursive(x, y, size/2);				// 2��и�
		recursive(x+size/2, y, size/2);			// 1��и� 
		recursive(x, y+size/2, size/2);			// 3��и�
		recursive(x+size/2, y+size/2, size/2);	// 4��и� 
		printf(")");
	}
	
	return;
} 
 
int main(void){
	int n;
	
	scanf("%d", &n);
	
	// �Է�
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	
	recursive(0, 0, n);

	return 0;
}

//8
//00000000
//00000000
//00001111
//00001111
//00011111
//00111111
//00111111
//00111111
