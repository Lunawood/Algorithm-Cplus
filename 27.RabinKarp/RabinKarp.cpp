#include <iostream>
// 라빈 카프(Rabin-Karp) 문자열 매칭 알고리즘 
// 해시를 사용. 단수 해시 알고리즘의 경우 연산속도가 O(1)이다.
// 문자열을 아스키코드로 숫자로 표현, 중복되는 경우가 있지만 거의 발생하지 않는다.
// 숫자를 차례대로 검사하기 때문에 O(N)의 시간복잡도를 갖는다.

using namespace std;

void findString(string parent, string pattern){
	int parentSize = parent.size();					// 긴문장 
	int patternSize = pattern.size();				// 찾는 문장 
	int parentHash = 0, patternHash = 0, power = 1;	// power: 제곱수 
	for(int i = 0; i <= parentSize - patternSize; i++){
		if(i == 0){
			for(int j = 0; j < patternSize; j++){
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if(j < patternSize - 1) power *= 2;
			}
		} else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}
		if(parentHash == patternHash){
			bool finded = true;
			for(int j = 0; j < patternSize; j++){
				if(parent[i + j] != pattern[j]){
					finded = false;
					break;
				}
			}
			if(finded){
				printf("%d번째에서 발견했습니다. \n", i + 1);
			}
		}
	}
}

int main(void){
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);
	return 0;
} 
