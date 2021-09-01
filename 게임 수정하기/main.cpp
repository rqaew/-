#include <iostream>
#include<cstdlib>
#include<ctime>
#include"Game.h"

using namespace std;
//Game클래스 선언

int main()
{
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여
	Game c1;
	Game::Die();
	Game c2;
	c2.Damage();
	c2.Damage();
	c2.Damage();
	c2.Die();
	return 0;
}