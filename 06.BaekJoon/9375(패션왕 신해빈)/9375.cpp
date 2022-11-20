#include<iostream>
#include<vector>
using namespace std;

vector<string> s;
vector<int> d;
// �ǻ� �з�
void clothes(string name){
	bool flag = false;
	// �� ���� +1
	for(int i = 0; i < s.size(); i++){
		if(s[i] == name) {
			d[i]++;	
			flag = true;
		}
	}
	// ���ο� �� �߰� 
	if(!flag){
		s.push_back(name);
		d.push_back(1);
	}
} 

int main(void){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		
		// �Է� 
		while(n--){
			string name;
			cin >> name >> name;	// �� ���� ������(���� �߿����� ����)
			clothes(name);
		}
		
		// �� {(x+1)(y+1)(z+1)...}-1
		int result = 1;
		for(int i = 0; i < d.size(); i++){
			result *= (d[i] + 1);
		}
		cout << result - 1 << endl;
		
		// �ʱ�ȭ 
		s.clear();
		d.clear();
	}
	return 0;
}
