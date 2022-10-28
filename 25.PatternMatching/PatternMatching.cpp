#include <iostream>

using namespace std;

// �ܼ� �� ���ڿ� ��Ī �˰��� : �ϳ��� Ȯ���ϴ� �˰���
// KMP���� ���� �˰���. 
// KMP(Knuth-Moriis-Pratt) �˰��� : ���ڿ� ��Ī �˰���
// ���� ������ ������ �˰���. O(N * M) ȿ�������� �ʴ�.
// M: ��ü �ε���, N: ã�� ���ڿ� ����
// �� O(N^2)�� ���� 

// parent �θ𿡼� pattern ������ ã�� �Լ� 
int findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize = pattern.size();
	// �̵��ϸ鼭 ���ڿ� ��  
	for(int i = 0; i <= parentSize - patternSize; i++){
		bool finded = true;
		// ��� ���ڿ��� �´��� Ȯ��  
		for(int j = 0; j < patternSize; j++){
			if(parent[i + j] != pattern[j]){
				// ù��° ���ڰ� Ʋ�� ��� �ٷ� �������� �� �ְ�
				// ���ǹ��� �߰��Ѵ�. 
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
		printf("ã�� �� �����ϴ�.");
	} else {
		printf("%d��°���� ã�ҽ��ϴ�.", result+1);
	}
	return 0;
}
