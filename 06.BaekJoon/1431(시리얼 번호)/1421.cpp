#include<iostream>
#include<algorithm>
using namespace std;

string a[20000];
int N; 
// 백준 1431번 시리얼 번호 

// getSum : 문제열에 들어있는 숫자를 뽑아서 더함값을 return 
int getSum(string a){
	int length = a.length(), sum = 0;
	for(int i = 0; i< length; i++){
		if(a[i] - '0' <= 9 && a[i] - '0' >= 0){
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b){
	if(a.length() == b.length()){
		int aSum = getSum(a);
		int bSum = getSum(b);
		// 글자의 포함된 숫자의 합이 다르다면
		if(aSum != bSum){
			return aSum < bSum;
		} else {
			return a < b;
		}
	} else {
		return a.length() < b.length();
	}
}

int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	sort(a, a + N, compare);
	
	for(int i = 0; i < N; i++){
		cout << a[i] << endl;
	}
	
	return 0;
}
