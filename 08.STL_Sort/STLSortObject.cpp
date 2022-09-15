#include <iostream>
#include <algorithm>
using namespace std;

// STL Sort ��ü ����

 class Student {
 	public:
 		string name;
 		int score;
 		Student(string name, int score){
 			this->name = name;
 			this->score = score;
		 }
		// ���� ������ '������ ���� ����'
		// �� ������ �����ε�...
		// return Ÿ�� operator ������(��ü�ּ� �Է�) 
		// ��ü���� �����ڸ� ������ �ּҸ� ���ϰų�
		// ��� ��� �������� ���ع�����.
		// ������ Ư�� ��� �������� ���ϰ� ���� ����
		// �񱳿����� �����ε��� ����ϸ� �ȴ�.
		// Student &student ��� ��ü �ҷ�����
		// �ڽ��� this->score�� �ҷ��� ��� ��ü student.score �� 
		// < �̸� true, >=�̸� false �� ���� ���� 
		bool operator <(Student &student){
			return this->score < student.score;
		}
 };
 
 int main(void){
 	Student students[] = {
	 	Student("�� �� ��", 90),
	 	Student("�� �� ��", 93),
	 	Student("�� �� ��", 97),
	 	Student("�� �� ��", 87),
	 	Student("�� �� ��", 92),
	 	Student("�� �� ��", 92),
	 };
	 
	sort(students, students + 6);
	
	for(int i = 0; i < 6; i++){
		cout << students[i].name << "\n";
	}
 }
