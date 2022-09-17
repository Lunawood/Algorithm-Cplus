#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
	if(a.length() < b.length()){
		return 1;
	} else if(a.length() > b.length()){
		return 0;
	} else {
		return a < b;
	}
}

// 배열 이름을 array라고 하면 백준에서는 오류가 납니다;; 
string a[20000];
int number;

int main(void) {
	cin >> number;

	for(int i = 0; i < number; i++){
		cin >> a[i];
	}
	
	sort(a, a + number, compare);
	
	for(int i = 0; i < number; i++){
		if(i > 0 && a[i] == a[i - 1]){
			continue;
		} else {
			cout << a[i] << '\n';
		}
	}
	
	return 0;
}
