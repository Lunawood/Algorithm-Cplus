#include <iostream>
#include <algorithm> 
using namespace std;
// C++ STL Sort 함수 다루기

// 정렬 기준 compare -> 오름차순 or 내림차순
// 더 작은 값이 앞으로 (a < b) 즉 오름차순 
bool compare(int a, int b){
	return a > b;
} 

int main(void){
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(a, a + 10, compare);
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
		
	}
	return 0;
}
