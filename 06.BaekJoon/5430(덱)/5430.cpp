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
 
// 제거 앞 
void df() {
	dq.pop_front();
}

// 제거 뒤 
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
			// 앞뒤 삭제 []
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
				reverse = !reverse;	// reverse 바꿔넣기
				cout << reverse << endl;
			} 
			else {	// D
				if(dq.size() > 0){
					if(reverse) df();
					else db();
				} else {
					flag = false;	// 오류 
					break;
				}
			} 
		}
		
		// 출력 
		if(flag){	
			cout << "[";
			while(1) {
				// dq이 비어있을때 출력하면 오류  
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
		
		// 초기화 
		reverse = true;
		dq.clear();
		v.clear();
	}
	
	return 0;
} 
