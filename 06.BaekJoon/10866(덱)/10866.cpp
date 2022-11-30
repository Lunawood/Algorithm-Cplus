#include <iostream>

using namespace std;

int a[20001];
int n, x;
int f = 10000, b = 10000;	// ó�� ����Ű�� �ּ� 
string s;
//push_front X: ���� X�� ���� �տ� �ִ´�.
//push_back X: ���� X�� ���� �ڿ� �ִ´�.
//pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//size: ���� ����ִ� ������ ������ ����Ѵ�.
//empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
//front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

bool empty(){
	return f == b;
}

void push_front(int x) {
	f -= 1;	// front�� �ּҸ� ������ ��� 
	a[f] = x;
}

int pop_front() {
	if(empty())	return -1;
	else {
		f += 1;	// front�� �ּҸ� �ڷ� ��. ���� �迭�� ��ĥ �ʿ�� ����. 
		return a[f-1];
	}
}

void push_back(int x){
	a[b] = x; 
	b += 1;	// back�� �ּҸ� �ڷ� ��.
}

int pop_back(){
	if(empty()) return -1;
	else {
		b -= 1;	// back�� �ּҸ� ������ ��� 
		return a[b];
	}
}

int size(){
	return abs(f - b);
}

int front(){
	if(empty()) return -1;
	else return a[f];
}

int back(){
	if(empty()) return -1;
	else return a[b-1];
}

int main(void){
	cin >> n;
	while(n--){
		cin >> s;
		if(s == "push_back"){
			cin >> x;
			push_back(x);
		} else if(s == "push_front"){
			cin >> x;
			push_front(x);
		} else if(s == "pop_front"){
			cout << pop_front() << "\n";
		} else if(s == "pop_back"){
			cout << pop_back() << "\n";
		} else if(s == "size"){
			cout << size() << "\n";
		} else if(s == "empty"){
			cout << empty() << "\n";
		} else if(s == "front"){
			cout << front() << "\n";
		} else if(s == "back"){
			cout << back() << "\n";
		}
	}
	return 0;
}
