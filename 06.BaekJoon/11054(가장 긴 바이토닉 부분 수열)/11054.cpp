#include<iostream>
#include<vector>
using namespace std;

// 가장 긴 바이토닉 부분 수열
 
int a[1001];
int d[1001];
int c[1001];
int N, mymax = 0;

void dp(){
	fill(d + 1, d + 1001, 1);
	// 가장 큰수를 기준으로 앞 수열 확인 
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			if(a[j] < a[i]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	fill(c + 1, c + 1001, 1);
	// 가장 큰수를 기준으로 뒤 수열 확인
	for(int l = N; l >= 1; l--){
		for(int k = N; k >= l; k--){
			if(a[k] < a[l]){
				c[l] = max(c[l], c[k] + 1);
			}
		} 
	}
	
	for(int i = 1; i <= N; i++){
		// 자기자신이 중복이 되므로 -1 
		mymax = max(mymax, c[i] + d[i] - 1);
	}
}

int main(void){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}
	
	dp();
	
	cout << mymax << endl;
	return 0;
}

