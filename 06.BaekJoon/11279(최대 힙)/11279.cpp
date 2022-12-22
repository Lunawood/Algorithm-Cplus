#include<iostream>
#define MAX 10000001 // ���� �ڽ����� ���ɼ� ���� OutOfBounds ���� 
#define SWAP(a, b) {long long tmp = a; a = b; b = tmp;}
using namespace std;

long long h[MAX];
long long x;
int n, cnt = 0;

int del(){
	// heap�� ��������� 0��� 
	if(cnt==0) return 0;
	
	long long root = h[1];
	// ������ ���Ҹ� root�� �Է� �� ���� 
	h[1] = h[cnt--];
	
	// heap���� 
	int c;
	int p = 1;
	while(true){
		c = p * 2;
		
		if(c + 1 <= cnt && h[c] < h[c+1]) c++;
		
		if(c > cnt || h[c] < h[p]) break;
		
		SWAP(h[p], h[c]);
		p = c;
	}
	
	return root;
}

void insert(long long x){
	// ������ ���ҿ� ��ġ
	cnt++;
	h[cnt] = x;
	
	int c = cnt;
	// ������ 
	while(true){
		if(c==1 or h[c] < h[c/2]) break;
		else {
			SWAP(h[c], h[c/2]);
		}
		c = c/2;
	}
}

void heap(long long x) {
	if(x == 0) printf("%d\n", del());
	else insert(x);
}

int main(void){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		heap(x);
	}
	return 0;
}
