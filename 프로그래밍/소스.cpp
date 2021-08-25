#include <stdio.h>
#include <iostream>
using namespace std;
class Person
{
private:
	string name_;
	int age_;
public:
	static int person_count_;
	Person(const string& name, int age);
	~Person() { person_count_--; }
	void showPersoninfo();
}; 
int Person::person_count_ = 0;
int main()
{
	Person hong("길동", 29);
	hong.showPersoninfo();
	Person lee("순신", 35);
	lee.showPersoninfo();

	return 0;
}
Person::Person(const string& name, int age) {
	name_ = name;
	age_ = age;
	cout << ++person_count_ << "번째 사람이 생성되었습니다." << endl;
}
void Person::showPersoninfo() {
	cout << "이 사람의 이름은 " << name_ << "이고, 나이는" << age_ << "살입니다." << endl;
}



