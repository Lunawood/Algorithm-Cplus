#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

// Value to Key 
string poketmonNtoS[100001];
// map ����: key(string), value(int)
map<string, int> poketmonStoN;
  
int main(){
	// cin, cout ����� �ӵ� ����
	// 1. scanf, prinf�� ��� ���x
	// 2. �̱� ������ ȯ�濡���� ����� ��
	// endl���� \n�� ����ϴ� ���� ������. 
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// N: ���� �Է� ����, M: ���� �Է� ���� 
	int N, M;
	cin >> N >> M;
	
	string info;
	for(int i = 0; i < N; i++){
		cin >> info;
		poketmonNtoS[i + 1] = info;
		poketmonStoN.insert(make_pair(info, i + 1)); 
	}

	string problem;
	for(int i = 0; i < M; i++){
		cin >> problem;
		
		if(0 < isdigit(problem[0]) and isdigit(problem[0]) < 10){
			cout << poketmonNtoS[stoi(problem)] << "\n";
		} else {
			auto item = poketmonStoN.find(problem);
			cout << item->second << "\n";
		}
	}
	
	return 0;
}
