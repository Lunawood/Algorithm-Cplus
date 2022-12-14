#include <iostream>
#include <vector>
using namespace std;

int zero, one, minusOne=0;
vector<vector<int> > a;
vector<int> w;

void func(int y, int x, int size){
	int cnt = a[y][x];
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(cnt != a[i][j]){
				// È¸±Í 9°¡Áö
				func(y, x, size/3);
				func(y + size/3, x, size/3);
				func(y + 2*size/3, x, size/3);
				func(y, x + size/3, size/3);
				func(y + size/3, x + size/3, size/3);
				func(y + 2*size/3, x + size/3, size/3);
				func(y, x + 2*size/3, size/3);
				func(y + size/3, x + 2*size/3, size/3);
				func(y + 2*size/3, x + 2*size/3, size/3);
				return;
			}
		}
	}
	
	if(a[y][x] == 0){
		zero++;
	} else if(a[y][x] == 1){
		one++;
	} else {
		minusOne++;
	}
	
	return;
}

int main(void){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int p;
			scanf("%d", &p);
			w.push_back(p);
		}
		a.push_back(w);
		w.clear();
	}
	
	func(0, 0, n);
	
	printf("%d\n%d\n%d", minusOne, zero, one);
	
	a.clear();
	
	return 0;
}
