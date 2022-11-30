#include <iostream>

using namespace std;

int a[20001];
int n, x;
int f = 10000, b = 10000;	// 처음 가리키는 주소 
string s;
//push_front X: 정수 X를 덱의 앞에 넣는다.
//push_back X: 정수 X를 덱의 뒤에 넣는다.
//pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 덱에 들어있는 정수의 개수를 출력한다.
//empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
//front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

bool empty(){
	return f == b;
}

void push_front(int x) {
	f -= 1;	// front의 주소를 앞으로 당김 
	a[f] = x;
}

int pop_front() {
	if(empty())	return -1;
	else {
		f += 1;	// front의 주소만 뒤로 밈. 따로 배열을 고칠 필요는 없음. 
		return a[f-1];
	}
}

void push_back(int x){
	a[b] = x; 
	b += 1;	// back의 주소를 뒤로 밈.
}

int pop_back(){
	if(empty()) return -1;
	else {
		b -= 1;	// back의 주소를 앞으로 당김 
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
