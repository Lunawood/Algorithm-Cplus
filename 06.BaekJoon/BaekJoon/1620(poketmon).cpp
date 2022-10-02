#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 
#include <sstream>
#include <stdlib.h> 
#include <queue>
using namespace std;

string InttoString[100001];
vector<pair<string, int> > StringtoInt;

// ���� Ž�� 
int binarySearch(string tmp, int s, int e){
	int m = (s + e) / 2;
	if(s > e) return 0;
	else {
		if(StringtoInt[m].first == tmp) {
			return StringtoInt[m].second;
		}
		else if(StringtoInt[m].first < tmp) return binarySearch(tmp, m + 1, e);
		else return binarySearch(tmp, s, m - 1);
	}
}

int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);	//������ �ð� �ʰ�
    
	int N, M, tot = 0;
	string tmp;
	queue<string> q;
	cin >> N >> M;
	for(int i = 1; i < N + 1; i++){
		cin >> tmp;
		InttoString[i] = tmp;	// ����->����, �迭 
		StringtoInt.push_back(make_pair(tmp, i));	// ����->����, vector 
	}
	
	// ���� ���� : ���� �˻��� ����ϱ� ���ؼ�... 
	sort(StringtoInt.begin(), StringtoInt.end());

	for(int i = 0; i < M; i++){
		cin >> tmp;
		int n;
		// ���ڿ� ���� ���� 
		if((int)isdigit(tmp.at(0))) {	// ���� -> ���� 
			n = atoi(&tmp.at(0));
			q.push(InttoString[n]);
		} else {	// ���� -> ���� 
			stringstream ss;
			ss << binarySearch(tmp, 0, N);
			q.push(ss.str());
		}
	}
	
	// ��� 
	while(q.size()){
		cout << q.front() << endl;
		q.pop();
	}
	
	return 0;
}

