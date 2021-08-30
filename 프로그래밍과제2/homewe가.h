#pragma once
#include <string>
#include <iostream>
using namespace std;
class Board
{
public:
	static string strBoard[15];
	static int count;
	static void add(const char* str) {
		string ss(str);
		strBoard[count] = ss;
		count++;
	}
	static void print() {
		cout << "**********게시판입니다***********" << endl;
		for (int i = 0; i < count; i++) {
			cout << strBoard[i] << endl;
		}
		cout << endl;
	}
};
