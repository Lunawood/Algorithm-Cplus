#include <iostream>
#include <string> 
#include <set>

// 11478 ���� �ٸ� �κ� ���ڿ��� ���� : ������ Ȱ���Ͽ� �ߺ��� �����ϴ� ���� 
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<string> se;
	string s;
	cin >> s;
	
	// ���ڿ��� ���̰� Ȧ���̸� +1, ¦���̸� +0. 
	int len = s.length();
	
	for(int i = 1; i <= len; i++){	// �κ������� ���� 
		// abc -> len = 3
		// (0, 1), (1, 1), (2, 1)
		// (0, 2), (1, 2)
		// (0, 3)
		for(int j = 0; j <= len - i; j++){
			string p = s.substr(j, i);
			// set�� ������ �߰� 
			se.insert(p);
		}
	}
	cout << se.size() << endl;
	return 0;
}
