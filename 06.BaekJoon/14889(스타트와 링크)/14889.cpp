#include <iostream>
#include <vector>
#include <cstdlib>	// 절대값 헤더파일 
using namespace std;

int stat[21][21];	// 20x20
int N;				// how many
int people[21];		// each person decides the team
vector<int> a;		// i, j
vector<int> tot;
int result = 0;

// 팀 능력 총합 
void TeamAbility(){
	for(int i = 1; i <= N; i++){
		if(people[i] == 1){
			a.push_back(i);
		}
	}
	for(int i = 0; i < a.size(); i++){
		for(int j = i + 1; j < a.size(); j++){
			// i, j의 Sij 와 Sji 능력치 합치기
			result += stat[a[i]][a[j]];
			result += stat[a[j]][a[i]];
		}
	}
	
	tot.push_back(result);

	// 결과 초기화 
	result = 0;
	// i, j 경우 초기화 
	a.clear();
}

// 팀나누기 
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

// 팀 차이의 최솟값 구하기 
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
	// 팀나누기 후 각각의 경우의 수일때 팀 능력 총합 구하기 
	DivTeam(1, 0);
	// 스타트팀과 링크 팀의 능력 차이의 최소값 
	Answer();
	
	return 0;
}
