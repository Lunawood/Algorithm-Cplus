#include <iostream>

using namespace std;

// 단순 비교 문자열 매칭 알고리즘 : 하나씩 확인하는 알고리즘
// KMP보다 쉬운 알고리즘. 
// KMP(Knuth-Moriis-Pratt) 알고리즘 : 문자열 매칭 알고리즘
// 가장 간단한 형태의 알고리즘. O(N * M) 효율적이지 않다.
// M: 전체 인덱스, N: 찾는 문자열 길이
// 즉 O(N^2)과 같다 

// parent 부모에서 pattern 패턴을 찾는 함수 
int findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize = pattern.size();
	// 이동하면서 문자열 비교  
	for(int i = 0; i <= parentSize - patternSize; i++){
		bool finded = true;
		// 모든 문자열이 맞는지 확인  
		for(int j = 0; j < patternSize; j++){
			if(parent[i + j] != pattern[j]){
				// 첫번째 문자가 틀린 경우 바로 빠져나올 수 있게
				// 조건문을 추가한다. 
				finded = false;
				break;
			}
		}
		if(finded){
			return i;
		}
	}
	return -1;
} 

int main(void){
	string parent = "Hello World";
	string pattern = "llo W";
	int result = findString(parent, pattern);
	if(result == -1){
		printf("찾을 수 없습니다.");
	} else {
		printf("%d번째에서 찾았습니다.", result+1);
	}
	return 0;
}
