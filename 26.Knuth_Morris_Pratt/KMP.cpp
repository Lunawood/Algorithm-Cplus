#include <iostream>
#include <vector>
using namespace std;
// �ִ���ġ���� 
// KMP(Knuth-Moriis-Pratt) �˰��� : ���ڿ� ��Ī �˰���.
// ���λ�� ���̻��� ������ Ȱ���Ͽ� �ݺ��Ǵ� ������ ���� ����
// ��Ī�� ���ڿ��� �ִ� ��ġ ���� ��ŭ ������ �����ϴ� ���. 

vector<int> makeTable(string pattern){
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);	// ���ڿ���ŭ 0�� ���̺� 
	int j = 0;
	for(int i = 1; i < patternSize; i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = table[j-1];	// ��ġ���� �ʴ� ��� j�� �� ĭ�� �ε����� ���Ұ��� �ο� 
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
