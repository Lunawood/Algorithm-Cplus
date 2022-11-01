#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int firMin, secMin, first;
int result = 1000000;
vector<int> v[3];
int N, x;

void searchMin(int idx, int Min){
	if(firMin > Min){
		secMin = firMin;
		firMin = Min;
		first = idx;
	} else {
		if(Min < secMin){
			secMin = Min;
		}
	}
}

void RGB(){
	for(int i = 0; i < N - 1; i++){
		firMin = 1000000;
		secMin = 1000000;
		first = 0;
		for(int j = 0; j < 3; j++){
			searchMin(j, v[j][i]);
		}
		for(int j = 0; j < 3; j++){
			if(j != first){
				v[j][i+1] += firMin;
			} else {
				v[j][i+1] += secMin;
			}
		}
	}
} 

int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			cin >> x;
			v[j].push_back(x);
		}
	}
	
	RGB();
	
	for(int j = 0; j < 3; j++){
		if(result > v[j][N-1]){
			result = v[j][N-1];
		}
	}	
	cout << result;

	return 0;
}
