#include <iostream>
#include <vector>
#include <cstdlib>	// ���밪 ������� 
using namespace std;

int stat[21][21];	// 20x20
int N;				// how many
int people[21];		// each person decides the team
vector<int> a;		// i, j
vector<int> tot;
int result = 0;

// �� �ɷ� ���� 
void TeamAbility(){
	for(int i = 1; i <= N; i++){
		if(people[i] == 1){
			a.push_back(i);
		}
	}
	for(int i = 0; i < a.size(); i++){
		for(int j = i + 1; j < a.size(); j++){
			// i, j�� Sij �� Sji �ɷ�ġ ��ġ��
			result += stat[a[i]][a[j]];
			result += stat[a[j]][a[i]];
		}
	}
	
	tot.push_back(result);

	// ��� �ʱ�ȭ 
	result = 0;
	// i, j ��� �ʱ�ȭ 
	a.clear();
}

// �������� 
void DivTeam(int idx, int n){
	if(n == N/2){ 
		for(int i = 1; i <= N; i++){
			cout << people[i] << " ";
		} cout << endl;
		TeamAbility();
		return;
	}
	for(int i = idx; i <= N; i++){
		if(people[i] == 0){
			people[i] = true;
			DivTeam(i, n+1);
			people[i] = false;
		}
	}
	return;
}

// �� ������ �ּڰ� ���ϱ� 
void Answer(){
	int min = abs(tot[0] - tot[tot.size() - 1]);
	for(int i = 1; i < tot.size()/2; i++){
		if(min > abs(tot[i] - tot[tot.size() - 1 - i])){
			min = abs(tot[i] - tot[tot.size() - 1 - i]);
		}
	}
	cout << min;
}

int main(void){
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> stat[i][j];
		}
	}
	// �������� �� ������ ����� ���϶� �� �ɷ� ���� ���ϱ� 
	DivTeam(1, 0);
	// ��ŸƮ���� ��ũ ���� �ɷ� ������ �ּҰ� 
	Answer();
	
	return 0;
}
