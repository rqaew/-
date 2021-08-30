#include <iostream>
#include <string.h>
#include "homewe가.h"

int Board::count = 0;
string Board::strBoard[] = { "", };
using namespace std;

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지를 많이 이용해 주세요");
	Board::print();
	Board::add("진소린 학생이 경진대회에 입상했습니다. 축하해주세요");
	Board::print();
}