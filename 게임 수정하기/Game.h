#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>


using namespace std;
//Game클래스 선언

void Atoa(char item) {
	if (item >= 'A' && item <= 'Z') {
		item += 32;
	}
}
class Game {
private:
	double energy = 200;
	int comenergy = 200;
	static int life;
	static int comlife;

public:
	Game();
	void battle();
	void comstance();
	void initcomstance();
	void initstance();
	double Damage(int n);
	static void Die();
	int comDamage(int n);
	bool attack = true;
	bool commid = false;
	bool comup = false;
	bool comleftup = false;
	bool comrigetup = false;
	bool comwaist = false;
	bool comreversewaist = false;
	bool comsonmoc = false;
	bool sonmoc = false;
	bool mid = false;
	bool up = false;
	bool leftup = false;
	bool rigetup = false;
	bool waist = false;
	bool reversewaist = false;
	
};
int Game::life = 10;
int Game::comlife = 10;
void Game::comstance() {
	srand((unsigned)time(NULL));
	int comstance = rand() % 6 + 1;
	switch (comstance)
	{
	case 1:
		comleftup = true;
		cout << "컴퓨터의 자세 = 좌상단"<<endl;
		break;

	case 2:
		comrigetup = true;
		cout << "컴퓨터의 자세 = 우상단"<<endl;
		break;
	case 3:
		comwaist = true;
		cout << "컴퓨터의 자세 = 허리(왼쪽)"<<endl;
		break;
	case 4:
		commid =true;
		cout << "컴퓨터의 자세 = 중단"<<endl;
		break;
	case 5:
		comreversewaist = true;
		cout << "컴퓨터의 자세 = 허리(오른쪽)"<<endl;
		break;
	case 6:
		comsonmoc = true;
		cout << "컴퓨터의 자세 = 손목 치기"<<endl;
		break;
	}
}
void Game::initcomstance() {
	bool commid = false;
	bool comup = false;
	bool comleftup = false;
	bool comrigetup = false;
	bool comwaist = false;
	bool comreversewaist = false;
	bool comsonmoc = false;
}
void Game::Die() {
	life--;
	cout << "**생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

}
double Game::Damage(int n) {
	srand((unsigned)time(NULL));
	int sumdamaged = rand() % 5;
	int damaged;
	if (n == 1) {
		damaged = 40 + sumdamaged;
	}
	else if (n == 2) {
		damaged = 25 + sumdamaged;
	}
	else if (n == 3) {
		damaged = 10 + sumdamaged;
	}
	if (energy > 0) {
		
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n"<<endl<<endl;
		if (energy < 0) {
			life--;
			energy = 200;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

		}
	}
	return energy;
}
int Game::comDamage(int n) {
	srand((unsigned)time(NULL));
	int sumdamaged = rand() % 5;
	int damaged = 0;
	if (n = 1) {
		damaged = 40 + sumdamaged;
	}
	else if (n = 2) {
		damaged = 25 + sumdamaged;
	}
	else if (n = 3) {
		damaged = 10 + sumdamaged;
	}
	else if (n = 4) {
		damaged = 50;
	}
	if (comenergy > 0) {

		comenergy -= damaged;
		cout << "컴퓨터의 에너지가 " << damaged << " 감소하여 " << comenergy << " 이 되었습니다.\n"<<endl<<endl;
		if (comenergy < 0) {
			comlife--;
			comenergy = 200;
			cout << "컴퓨터의 생명이 1 감소하여 " << comlife << "이 되었습니다." << endl << endl;

		}
	}
	return comenergy;
}
void Game::initstance() {
	bool mid = false;
	bool up = false;
	bool leftup = false;
	bool rigetup = false;
	bool waist = false;
	bool reversewaist = false;
}
void Game::battle() {

	cout << "_______________________________________________";
	char stance; // 자세 q,w,e,a,s,d

	cin >> stance;
	Atoa(stance);

	switch (stance) {
	case 'q':
		leftup = true;
		cout << "당신의 자세 = 좌상단"<<endl;
		break;
	case 'w':
		up = true;
		cout << "당신의 자세 = 상단"<<endl;	
		break;
	case 'e':
		rigetup = true;
		cout << "당신의 자세 = 우상단"<<endl;
		break;
	case 'a':
		waist = true;
		cout << "당신의 자세 = 허리(왼쪽)"<<endl;
		break;
	case 's':
		mid = true;
		cout << "당신의 자세 = 중단"<<endl;
		break;
	case 'd':
		reversewaist = true;
		cout << "당신의 자세 = 허리(오른쪽)"<<endl;
		break;
	case 'x':
		sonmoc = true;
		cout << "당신의 자세 = 손목 치기"<<endl;
		break;
	}


	if (attack == true) {
		if (leftup == true) {
			comstance();
			if (comleftup == true) {
				attack = false;
				cout << "공격이 막힘!"<<endl;
				cout << "공격권이 넘어갔습니다."<<endl;
				attack = false;
			}

			else if (commid == true) {
				attack = false;
				cout << "공격이 막힘!"<<endl;
				cout << "공격권이 넘어갔습니다."<<endl;
				cout << "중단 상태의 적에게 머리 공격을하였습니다."<<endl;
				cout << "10~15데미지"<<endl;
				Damage(3);
			}
			else {
				cout << "머리공격에 성공했습니다." << endl;
				cout << "상대에게 40~45의 데미지를 주었습니다."<<endl;
				comDamage(1);
			}
			initcomstance();
			initstance();
		}
		else if (up == true) {
			cout << "상단 자세에서는 공격권이 없더라도 다음턴에 키를 한번 더 눌러서 변칙적인 공격을 할 수 있습니다."<<endl;
			cout << "또한 상대의 머리 공격을 방어할 수 있습니다."<<endl;
			comstance();
			if (comleftup == true || comrigetup == true) {
				cout << "방어에 성공했습니다."<<endl;
			}
			else if (commid) {
				cout << "상대의 자세가 중단입니다." << endl;
				cout << "데미지가 없습니다."<<endl;
			}
			else {
				cout << "허리공격에 당했습니다."<<endl;
				cout << "25~30데미지"<<endl;
				Damage(2);
			}
			initcomstance();
			
			stance = 'm';
			cout <<endl<< "현제 상단자세 입니다. 다음 자세를 골라주세요(상단세 뒤에는 공격력이 상승합니다.)" << endl;
			cout << "(상단세을 다시 선택할 수 없습니다.)"<<endl;
			cin >> stance;
			switch (stance) {
			case 'q':
				leftup = true;
				cout << "당신의 자세 = 좌상단"<<endl;
				break;
			case 'w':
				up = true;
				cout << "아 ㅋㅋ 선택하지 말라고"<<endl;
				cout << "님 턴 걍 넘어감 ㅅㄱ"<<endl;
				break;
			case 'e':
				rigetup = true;
				cout << "당신의 자세 = 우상단"<<endl;
				break;
			case 'a':
				waist = true;
				cout << "당신의 자세 = 허리(왼쪽)"<<endl;
				break;
			case 's':
				mid = true;
				cout << "당신의 자세 = 중단"<<endl;
				break;
			case 'd':
				reversewaist = true;
				cout << "당신의 자세 = 허리(오른쪽)"<<endl;
				break;
			}
			comstance();
			if (leftup) {
				if (comleftup) {
					cout << "공격이 막혔습니다."<<endl;
				}
				else if (commid) {
					cout << "중단상태인 적에게 머리공격을 했습니다"<<endl;
					cout << "나에게10~15 데미지"<<endl;
					Damage(3);
				}
				else {
					cout << "머리공격에 성공했습니다."<<endl;
					cout << "상단세 였기 때문에 추가 데미지가 들어갑니다."<<endl;
					comDamage(4);
				}
				initstance();
				initcomstance();
			}
			
		}
		else if (rigetup == true) {
			comstance();
			if (comrigetup == true) {
				attack = false;
				cout << "공격이 막힘!"<<endl;
				cout << "공격권이 넘어갔습니다."<<endl;
				attack = false;
			}

			else if (commid == true) {
				attack = false;
				cout << "공격이 막힘!"<<endl;
				cout << "공격권이 넘어갔습니다."<<endl;
				cout << "중단 상태의 적에게 머리 공격을하였습니다."<<endl;
				cout << "나에게10~15데미지"<<endl;
				Damage(3);
				
			}
			else {
				cout << "머리공격에 성공했습니다."<<endl;
				cout << "상대에게 40~45의 데미지를 주었습니다."<<endl;
				cout << "남은 상대의 체력 = " << comenergy<<endl;
				comDamage(1);
			}
			initcomstance();
			initstance();
		}
		else if (waist == true) {
		comstance();
		if (comwaist == true) {
			attack = false;
			cout << "공격이 막힘!"<<endl;
			cout << "공격권이 넘어갔습니다."<<endl;
			attack = false;
		}

		else if (commid == true) {
			attack = false;
			cout << "공격이 막힘!"<<endl;
			cout << "공격권이 넘어갔습니다."<<endl;
			cout << "중단 상태의 적에게 허리 공격을하였습니다."<<endl;
			cout << "나에게10~15데미지"<<endl;
			Damage(3);
			
		}
		else {
			cout << "허리공격에 성공했습니다."<<endl;
			cout << "상대에게 25~30의 데미지를 주었습니다."<<endl;
			comDamage(2);
		}
		initcomstance();
		initstance();
}
		else if (reversewaist == true) {
		comstance();
		if (comreversewaist == true) {
			attack = false;
			cout << "공격이 막힘!"<<endl;
			cout << "공격권이 넘어갔습니다."<<endl;
			attack = false;
		}

		else if (commid == true) {
			attack = false;
			cout << "공격이 막힘!"<<endl;
			cout << "공격권이 넘어갔습니다."<<endl;
			cout << "중단 상태의 적에게 허리 공격을하였습니다."<<endl;
			cout << "나에게10~15데미지"<<endl;
			Damage(3);
		}
		else {
			cout << "허리공격에 성공했습니다."<<endl;
			cout << "상대에게 25~30의 데미지를 주었습니다."<<endl;
			Damage(2);
		}
		initcomstance();
		initstance();
}
		else if (mid == true) {
		comstance();
		if (commid == true) {
			cout << "서로 중단입니다."<<endl;
			cout << "아무일도 일어나지 않았습니다."<<endl;
		}
		else if (comsonmoc == true) {
			cout << "손목 공격을 맞았습니다."<<endl;
			cout << "데미지 25~30"<<endl;
			Damage(2);
		}
		else {
			cout << "상대방이 중단상태에 공격을 가했습니다"<<endl;
			cout << "상대방에게 데미지 10~15"<<endl;
			comDamage(3);
		}
		initcomstance();
		initstance();
}
		else if (sonmoc == true) {
		comstance();
		if (commid == true) {
			cout << "상대방은 중단입니다."<<endl;
			cout << "손목 공격을 성공했습니다."<<endl;
			Damage(2);
		}
		else if (comsonmoc == true) {
			cout << "공격이 막혔습니다"<<endl;
			cout << "공격권이 넘어갑니다"<<endl;
			attack = false;
		}
		else {
			cout << "상대방에게 공격을 맞았습니다."<<endl;
			cout << "25~30의 데미지"<<endl;
			Damage(2);
		}
		initcomstance();
		initstance();
}
	}
	else if (attack == false) {
		if (leftup == true) {
			comstance();
			if (comleftup == true) {
				attack = false;
				cout << "공격을 막음!"<<endl;
				cout << "공격권이 넘어왔습니다."<<endl;
				attack = true;
			}

			else if (commid == true) {
				cout << "나니모... 나캇따.(상대가 방어만함)"<<endl;
				cout << "공격권을 가져왔습니다"<<endl;
				attack = true;
			}
			else {
				cout << "공격에 당했습니다."<<endl;
				cout << "25~30의 데미지를 받습니다."<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (up == true) {
			cout << "상단 에서는 공격권이 없더라도 다음턴에 키를 한번 더 눌러서 변칙적인 공격을 할 수 있습니다."<<endl;
			cout << "또한 상대의 머리 공격을 방어할 수 있습니다."<<endl;
			comstance();
			if (comleftup == true || comrigetup == true) {
				cout << "방어에 성공했습니다."<<endl;
			}
			else if (commid) {
				cout << "상대의 자세가 중단입니다."<<endl;
				cout << "데미지가 없습니다."<<endl;
			}
			else {
				cout << "허리공격에 당했습니다."<<endl;
				cout << "25~30데미지"<<endl;
				Damage(2);
			}
			initcomstance();
			comstance();
			cout << "현제 상단자세 입니다. 다음 자세를 골라주세요(상단세 뒤에는 공격력이 상승합니다.)"<<endl;
			cout << "(상단세을 다시 선택할 수 없습니다.)"<<endl;
			cin >> stance;
			switch (stance) {
			case 'q':
				leftup = true;
				cout << "당신의 자세 = 좌상단"<<endl;
				break;
			case 'w':
				up = true;
				cout << "아 ㅋㅋ 선택하지 말라고"<<endl;
				cout << "님 턴 걍 넘어감 ㅅㄱ"<<endl;
				break;
			case 'e':
				rigetup = true;
				cout << "당신의 자세 = 우상단"<<endl;
				break;
			case 'a':
				waist = true;
				cout << "당신의 자세 = 허리(왼쪽)"<<endl;
				break;
			case 's':
				mid = true;
				cout << "당신의 자세 = 중단"<<endl;
				break;
			case 'd':
				reversewaist = true;
				cout << "당신의 자세 = 허리(오른쪽)"<<endl;
				break;
			}
			if (leftup) {
				if (comleftup) {
					cout << "공격이 막혔습니다."<<endl;
				}
				else if (commid) {
					cout << "중단상태인 적에게 머리공격을 했습니다"<<endl;
					cout << "10~15 데미지"<<endl;
					Damage(3);
				}
				else {
					cout << "머리공격에 성공했습니다."<<endl;
					cout << "상단세 였기 때문에 추가 데미지가 들어갑니다."<<endl;
					comDamage(4);
				}
				initstance();
			}

		}
		else if (rigetup == true) {
			comstance();
			if (comrigetup == true) {
				attack = false;
				cout << "공격을 막음!"<<endl;
				cout << "공격권이 넘어왔습니다."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "나니모...나카타...(상대가 방어만함)"<<endl;
			}
			else {
				cout << "공격에 당했습니다."<<endl;
				cout << "상대에게 25~30의 데미지를 받았습니다."<<endl;
				comDamage(2);
			}
			initcomstance();
			initstance();
		}
		else if (waist == true) {
			comstance();
			if (waist == true) {
				attack = false;
				cout << "공격을 막음!"<<endl;
				cout << "공격권이 넘어옵니다."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "나니모.......나카타!!!!!!!  (상대가 방어만함)"<<endl;
			}
			else {
				cout << "공격에 당했습니다"<<endl;
				cout << "25~30데미지"<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (reversewaist == true) {
			comstance();
			if (comreversewaist == true) {
				cout << "공격을 막음!"<<endl;
				cout << "공격권이 넘어왔습니다."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "나니모...나캇타(상대가 방어만함)"<<endl;
			}
			else {
				cout << "허리공격에 성공했습니다."<<endl;
				cout << "상대에게 25~30의 데미지를 주었습니다."<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (mid == true) {
			comstance();
			if (commid == true) {
				cout << "서로 중단입니다."<<endl;
				cout << "아무일도 일어나지 않았습니다."<<endl;
			}
			else if (comsonmoc == true) {
				cout << "손목 공격을 맞았습니다."<<endl;
				cout << "데미지 25~30"<<endl;
				Damage(2);
			}
			else {
				cout << "상대방이 중단상태에 공격을 가했습니다"<<endl;
				cout << "상대방에게 데미지 10~15"<<endl;
				comDamage(3);
			}
			initcomstance();
			initstance();
		}
		else if (sonmoc == true) {
			comstance();
			if (commid == true) {
				cout << "상대방은 중단입니다."<<endl;
				cout << "손목 공격을 성공했습니다."<<endl;
				Damage(2);
			}
			else if (comsonmoc == true) {
				cout << "공격이 막았습니다"<<endl;
				cout << "공격권이 넘어옵니다"<<endl;
				attack = true;
			}
			else {
				cout << "상대방에게 공격을 맞았습니다."<<endl;
				cout << "25~30의 데미지"<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
	}

}
Game::Game()
{
	cout << "게임 설명"<<endl;
	cout << "q = 좌상단, w = 상단, e = 우상단" << endl;
	cout << "a = 허리  , s = 중단, d = 역허리" << endl;
	cout << "            x = 손목" << endl<<endl;
	cout << "공격권이 있는 상태로 시작하며 공격을 같은 자세로 막아지면 공격권이 넘어가거나 넘어옵니다." << endl;
	cout << "중단상태의 적에게 공격을 하면 역으로 데미지를 입습니다." << endl;
	cout << "중단상태의 적은 손목으로만 공격할 수 있습니다.";
	cout << "w(상단)자세는 모든 머리 공격을 방어할 수 있지만 한턴동안 공격할 수 없습니다." << endl;
	cout << "대신 다음차레의 공격력이 증가합니다." << endl;
	do 
	{
		battle();
	} while (life!=0);


}