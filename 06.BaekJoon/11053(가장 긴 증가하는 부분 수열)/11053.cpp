#include<iostream>
#include<vector>
using namespace std;

int a[1001];
int d[1001];
int N, cnt, mymax = 1;

void dp(){
	fill(d, d + 1001, 1);
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= i; j++){
			if(a[j] < a[i]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
		mymax = max(mymax, d[i]);
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
