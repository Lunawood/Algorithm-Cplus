#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// const : 값을 변경할 수 없게 함. 대신 주소값은 변경 가능
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
	// test 횟수 
	int T;
    cin >> T;
    
    // 문자 입력 Null값 포함
	// 포인터 문자열은 읽기전용, 쓰기가 안됨 Error 
    char ptr[T][1001];
    for(int i = 0; i < T; i++){
    	cin >> ptr[i];
	}
	
	// 결과 출력
	for(int i = 0; i < T; i++){
		isPalindrome(ptr[i], 1);
	}
	
	return 0; 
}
