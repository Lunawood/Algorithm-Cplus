#include<iostream>
#include<algorithm>
using namespace std;

string a[20000];
int N; 
// ���� 1431�� �ø��� ��ȣ 

// getSum : �������� ����ִ� ���ڸ� �̾Ƽ� ���԰��� return 
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
		// ������ ���Ե� ������ ���� �ٸ��ٸ�
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
