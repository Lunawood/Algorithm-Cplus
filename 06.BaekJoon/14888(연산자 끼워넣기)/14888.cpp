#include<iostream>
#include<vector>
#include<queue>
#define MAX -1000000000
#define MIN 1000000000 
using namespace std;

// 숫자가 있고 그 사이에 연산자를 끼워넣어서 경우의 수를 모두 만들면...
vector<int>	num;			// 숫자
int Max = MAX, Min = MIN;	// 최댓값, 최솟값 
int Opt[4], N;				// 연산자, 숫자 개수 

// 앞에서부터 계산해주는 함수
int cal(int a, int b, int opt){
	switch(opt){
		case 0:
			return a + b;
		case 1:
			return a - b;
		case 2:
			return a * b;
		case 3:
			return a / b;
	}
	return 0;
}

void backtracking(int n, int result){
	if(n == N){
		if(Max < result){
			Max = result;
		}
		if(Min > result){
			Min = result;
		}
		return;
	}
	
	for(int i = 0; i < 4; i++){
		if(Opt[i] > 0){
			Opt[i]--;
			backtracking(n + 1, cal(result, num[n], i));
			Opt[i]++;
		}
	} 
	return;
}

int main(void){
	int x;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x;
		num.push_back(x);
	}
	
	for(int i =  0; i < 4; i++){
		cin >> Opt[i];
	}
	
	backtracking(1, num[0]);
	
	cout << Max << endl;
	cout << Min << endl;
	
	return 0;
}
