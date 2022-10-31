#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int mymax = -1000000000;
int result = 0;
void sum(int n){
	for(int i = 0; i < n; i++){
		result += v[i];
		if(result < v[i]){
			result = v[i];
		}
		if(mymax < result){
			mymax = result;
		}
	}
	cout << mymax << endl;
}
int main(void){
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);	
	}
	sum(n);
	return 0;
}
