#include <iostream>
#include <string.h>
#include "homewe��.h"

int Board::count = 0;
string Board::strBoard[] = { "", };
using namespace std;

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ������� ���� �̿��� �ּ���");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ�� �Ի��߽��ϴ�. �������ּ���");
	Board::print();
}