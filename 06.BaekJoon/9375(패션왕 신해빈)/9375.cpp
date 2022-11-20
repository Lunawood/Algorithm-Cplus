#include<iostream>
#include<vector>
using namespace std;

vector<string> s;
vector<int> d;
// 의상 분류
void clothes(string name){
	bool flag = false;
	// 옷 종류 +1
	for(int i = 0; i < s.size(); i++){
		if(s[i] == name) {
			d[i]++;	
			flag = true;
		}
	}
	// 새로운 옷 추가 
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
		
		// 입력 
		while(n--){
			string name;
			cin >> name >> name;	// 앞 내용 버리기(앞은 중요하지 않음)
			clothes(name);
		}
		
		// 식 {(x+1)(y+1)(z+1)...}-1
		int result = 1;
		for(int i = 0; i < d.size(); i++){
			result *= (d[i] + 1);
		}
		cout << result - 1 << endl;
		
		// 초기화 
		s.clear();
		d.clear();
	}
	return 0;
}
