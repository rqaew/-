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
	Person hong("�浿", 29);
	hong.showPersoninfo();
	Person lee("����", 35);
	lee.showPersoninfo();

	return 0;
}
Person::Person(const string& name, int age) {
	name_ = name;
	age_ = age;
	cout << ++person_count_ << "��° ����� �����Ǿ����ϴ�." << endl;
}
void Person::showPersoninfo() {
	cout << "�� ����� �̸��� " << name_ << "�̰�, ���̴�" << age_ << "���Դϴ�." << endl;
}



