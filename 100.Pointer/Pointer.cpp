#include <iostream>
using namespace std;

// 포인터는 변수이다. 포인터는 변수값을 저장하는 것이 아닌
// 변수의 주소를 저장한다. 

// &: 주소 연산자
// *: 참조 연산자 
void arr_pointer1(int* x){
	cout << x << endl;
	cout << *x << endl;
}
void arr_pointer2(int **x){
	cout << x << endl;	// x의 주소
	cout << *x << endl; // x의 값
	//cout << **x << endl; // 배열의 값 
}
void arr_pointer3(int x){
	cout << x << endl;
}

int main(void){
	int x[3] = {1,2,3};
	// x는 주소를 저장
	arr_pointer1(x); 
	int* p = x;
	arr_pointer2(&p); 
	//arr_pointer2(&x); 배열은 주소를 생성한 후 사용할 수 없다. 
	arr_pointer3(*x);
} 
