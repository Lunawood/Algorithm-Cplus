#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// const : ���� ������ �� ���� ��. ��� �ּҰ��� ���� ����
void result(int b, int n){
	cout << b << " " << n << endl;
}

void recursion(const char *s, int l, int r, int n){
    if(l >= r) return result(1, n);
    else if(s[l] != s[r]) return result(0, n);
    else return recursion(s, l+1, r-1, n + 1);
}

void isPalindrome(const char *s, int n){
    return recursion(s, 0, strlen(s)-1, n);
}

int main(){
	// test Ƚ�� 
	int T;
    cin >> T;
    
    // ���� �Է� Null�� ����
	// ������ ���ڿ��� �б�����, ���Ⱑ �ȵ� Error 
    char ptr[T][1001];
    for(int i = 0; i < T; i++){
    	cin >> ptr[i];
	}
	
	// ��� ���
	for(int i = 0; i < T; i++){
		isPalindrome(ptr[i], 1);
	}
	
	return 0; 
}
