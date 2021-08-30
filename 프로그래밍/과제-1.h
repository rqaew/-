#pragma once

class Person
{
public:
	int money;
	static int sharedMoney;
	void addMoney(int n) {
		money += n;
	}
	void addShared(int n) {
		sharedMoney += n;
	}
};
