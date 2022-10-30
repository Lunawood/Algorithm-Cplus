#include<iostream>

using namespace std;

int w[101][101][101];

int dp(int a, int b, int c){
	if(a <= 0 or b <= 0 or c <= 0){
		if(w[a+50][b+50][c+50] != 0){
			return w[a+50][b+50][c+50];
		}
		return w[a+50][b+50][c+50] = 1;
	} else if(a > 20 or b > 20 or c > 20) {
		if(w[a+50][b+50][c+50] != 0){
			return w[a+50][b+50][c+50];
		}
		return w[a+50][b+50][c+50] = dp(20, 20, 20);	
	} else if(a < b and b < c){
		if(w[a+50][b+50][c+50] != 0){
			return w[a+50][b+50][c+50];
		}
		return w[a+50][b+50][c+50] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);	
	} else {
		if(w[a+50][b+50][c+50] != 0){
			return w[a+50][b+50][c+50];
		}
		return w[a+50][b+50][c+50] = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) - dp(a-1, b-1, c-1);
	}
}

void Answer(int a, int b, int c){
	while(1) {
		cin >> a >> b >> c;
		if(a == -1 and b == -1 and c == -1){
			break;
		}
		cout << "w(" << a << ", ";
		cout << b << ", ";
		cout << c << ") = ";
		cout << dp(a, b, c) << endl;
	}
}

int main(void){
	int a, b, c;
	Answer(a, b, c);
	return 0;
}
