#include <iostream>
#include <vector>
using namespace std;
// 최대일치길이 
// KMP(Knuth-Moriis-Pratt) 알고리즘 : 문자열 매칭 알고리즘.
// 접두사와 접미사의 개념을 활용하여 반복되는 연산을 줄인 다음
// 매칭할 문자열을 최대 일치 길이 만큼 빠르게 점프하는 기법. 

vector<int> makeTable(string pattern){
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);	// 문자열만큼 0인 테이블 
	int j = 0;
	for(int i = 1; i < patternSize; i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = table[j-1];	// 일치하지 않는 경우 j를 한 칸뒤 인덱스의 원소값을 부여 
		}
		if(pattern[i] == pattern[j]){
			table[i] = ++j;
		}
	}
	return table;
}

int main(void){
	string pattern = "abacaaba";
	vector<int> table = makeTable(pattern);
	for(int i = 0; i < table.size(); i++){
		cout << table[i] << " ";
	}
	return 0;
}
