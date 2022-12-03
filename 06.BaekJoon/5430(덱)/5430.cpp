#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

deque<int> dq;
vector<string> v;
int t, p;
string s;
string x;
bool reverse = true;
 
// ���� �� 
void df() {
	dq.pop_front();
}

// ���� �� 
void db() {
	dq.pop_back();
}

int main(void){
	cin >> t;
	while(t--){
		bool flag = true;
		cin >> s;
		cin >> p;
		cin >> x;
		 
		if(x.size() >= 2){
			// �յ� ���� []
			x.erase(0, 1);
			x.erase(x.size()-1, 1);
		}
		
		if(x.size() > 0){
			// split
			istringstream ss(x);
			string stringbuffer;
			while(getline(ss, stringbuffer, ',')){
				v.push_back(stringbuffer);
			}
			
			// string to int 
			for(int i = 0; i < v.size(); i++){
				dq.push_back(stoi(v[i]));
			}
		}
		
		// D or R
		for(int i = 0; i < s.size(); i++){
			if(s[i]=='R') {
				cout << reverse << " -> ";
				reverse = !reverse;	// reverse �ٲ�ֱ�
				cout << reverse << endl;
			} 
			else {	// D
				if(dq.size() > 0){
					if(reverse) df();
					else db();
				} else {
					flag = false;	// ���� 
					break;
				}
			} 
		}
		
		// ��� 
		if(flag){	
			cout << "[";
			while(1) {
				// dq�� ��������� ����ϸ� ����  
				if(!dq.empty()) {
					if(reverse){
						cout << dq.front();
						dq.pop_front();
					} else {
						cout << dq.back();
						dq.pop_back();
					}
				}
				if(dq.empty()) break;
				cout << ",";
			}
			cout << "]" << endl;
		} else {
			cout << "error" << endl;
		}
		
		// �ʱ�ȭ 
		reverse = true;
		dq.clear();
		v.clear();
	}
	
	return 0;
} 
