#include <iostream>
#include<cstdlib>
#include<ctime>
#include"Game.h"

using namespace std;
//GameŬ���� ����

int main()
{
	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�
	Game c1;
	Game::Die();
	Game c2;
	c2.Damage();
	c2.Damage();
	c2.Damage();
	c2.Die();
	return 0;
}