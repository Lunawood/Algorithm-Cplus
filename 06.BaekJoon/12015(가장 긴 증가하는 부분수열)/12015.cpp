#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<int> v;

int main(void){
	scanf("%d", &n);
	
	long long a[n];
	
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	
	v.push_back(0);
	
	for(int i = 0; i < n; i++){
		int x = a[i];
		
		if(v.back() < x) {
			v.push_back(a[i]);
		}
		else {
			int index = lower_bound(v.begin(), v.end(), x) - v.begin();
			v[index] = x;
		}
	}
	
	cout << v.size() - 1 << endl;
	return 0;
}

//6
//10 20 40 10 15 30
