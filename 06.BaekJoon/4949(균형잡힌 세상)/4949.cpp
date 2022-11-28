#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> s;
string sentence;

int main(void){
	// ���� ����
	do {
		getline(cin, sentence);
		if(sentence[0] == '.') break;
		
		for(int i = 0; i < sentence.size() - 1; i++){
			
			if(sentence[i] == '[' or sentence[i] == '('){
				s.push(sentence[i]);
			}
			if(sentence[i] == ']'){
				if(!s.empty() and  s.top() == '['){
					s.pop();
				} else {
					s.push('a');
					break;
				}
			}
			if(sentence[i] == ')'){
				if(!s.empty() and s.top() == '('){
					s.pop();
				} else {
					s.push('a');
					break;
				}
			}
		}
		
		// ��� 
		if(s.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
		
		// �ʱ�ȭ
		sentence.clear();
		while(!s.empty()) {
			s.pop();
		}
	} while(1);
 
	return 0;
}
