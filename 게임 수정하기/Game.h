#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
//Game클래스 선언

class Game {
private:
	double energy = 100;
	static int life;

public:
	Game();
	double Damage();
	static void Die();
};
int Game::life = 10;

void Game::Die() {
	life--;
	cout << "**생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

		}
	}
	return energy;
}

Game::Game()
{
	cout << "에너지가 " << energy << " 이며, 생명이 " << life << "인 캐릭터가 만들어졌습니다.\n";
	Damage();
	Damage();
	Damage();
	Damage();
	Damage();

}