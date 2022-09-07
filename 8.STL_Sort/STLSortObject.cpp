#include <iostream>
#include <algorithm>
using namespace std;

// STL Sort 객체 정렬

 class Student {
 	public:
 		string name;
 		int score;
 		Student(string name, int score){
 			this->name = name;
 			this->score = score;
		 }
		// 정렬 기준은 '점수가 작은 순서'
		// 비교 연산자 오버로딩...
		// return 타입 operator 연산자(객체주소 입력) 
		// 객체끼리 연산자를 넣으면 주소를 비교하거나
		// 어떠한 멤버 변수값을 비교해버린다.
		// 하지만 특정 멤버 변수값을 비교하고 싶을 때는
		// 비교연산자 오버로딩을 사용하면 된다.
		// Student &student 상대 객체 불러오기
		// 자신의 this->score과 불러온 상대 객체 student.score 비교 
		// < 이면 true, >=이면 false 즉 오름 차순 
		bool operator <(Student &student){
			return this->score < student.score;
		}
 };
 
 int main(void){
 	Student students[] = {
	 	Student("나 동 빈", 90),
	 	Student("이 상 욱", 93),
	 	Student("박 한 울", 97),
	 	Student("강 종 구", 87),
	 	Student("이 태 일", 92),
	 	Student("이 태 이", 92),
	 };
	 
	sort(students, students + 6);
	
	for(int i = 0; i < 6; i++){
		cout << students[i].name << "\n";
	}
 }
