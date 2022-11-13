#include <iostream>
#include <string.h>
using namespace std;

char s[200001];
int q, l, r;
char c;
int n[26][200001];	// 알파벳 위치 정보 

int main(void){
	scanf("%s\n%d", &s, &q);
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < strlen(s); j++){
			if(j > 0) n[i][j] = n[i][j-1];
			if(i == s[j] - 'a') n[i][j]++;
		}
	}
	
	for(int i = 0; i < q; i++){
		scanf("%s %d %d", &c, &l, &r);
		int result = 0;
		if(l == 0)	printf("%d\n", n[c-'a'][r]);
		else printf("%d\n", n[c-'a'][r] - n[c-'a'][l-1]);
	}
	
	return 0;
}
