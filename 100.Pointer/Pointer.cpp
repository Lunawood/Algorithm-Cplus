#include <iostream>
using namespace std;

// �����ʹ� �����̴�. �����ʹ� �������� �����ϴ� ���� �ƴ�
// ������ �ּҸ� �����Ѵ�. 

// &: �ּ� ������
// *: ���� ������ 
void arr_pointer1(int* x){
	cout << x << endl;
	cout << *x << endl;
}
void arr_pointer2(int **x){
	cout << x << endl;	// x�� �ּ�
	cout << *x << endl; // x�� ��
	//cout << **x << endl; // �迭�� �� 
}
void arr_pointer3(int x){
	cout << x << endl;
}

int main(void){
	int x[3] = {1,2,3};
	// x�� �ּҸ� ����
	arr_pointer1(x); 
	int* p = x;
	arr_pointer2(&p); 
	//arr_pointer2(&x); �迭�� �ּҸ� ������ �� ����� �� ����. 
	arr_pointer3(*x);
} 
