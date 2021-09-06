#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>


using namespace std;
//GameŬ���� ����

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
		cout << "��ǻ���� �ڼ� = �»��"<<endl;
		break;

	case 2:
		comrigetup = true;
		cout << "��ǻ���� �ڼ� = ����"<<endl;
		break;
	case 3:
		comwaist = true;
		cout << "��ǻ���� �ڼ� = �㸮(����)"<<endl;
		break;
	case 4:
		commid =true;
		cout << "��ǻ���� �ڼ� = �ߴ�"<<endl;
		break;
	case 5:
		comreversewaist = true;
		cout << "��ǻ���� �ڼ� = �㸮(������)"<<endl;
		break;
	case 6:
		comsonmoc = true;
		cout << "��ǻ���� �ڼ� = �ո� ġ��"<<endl;
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
	cout << "**������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

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
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n"<<endl<<endl;
		if (energy < 0) {
			life--;
			energy = 200;
			cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

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
		cout << "��ǻ���� �������� " << damaged << " �����Ͽ� " << comenergy << " �� �Ǿ����ϴ�.\n"<<endl<<endl;
		if (comenergy < 0) {
			comlife--;
			comenergy = 200;
			cout << "��ǻ���� ������ 1 �����Ͽ� " << comlife << "�� �Ǿ����ϴ�." << endl << endl;

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
	char stance; // �ڼ� q,w,e,a,s,d

	cin >> stance;
	Atoa(stance);

	switch (stance) {
	case 'q':
		leftup = true;
		cout << "����� �ڼ� = �»��"<<endl;
		break;
	case 'w':
		up = true;
		cout << "����� �ڼ� = ���"<<endl;	
		break;
	case 'e':
		rigetup = true;
		cout << "����� �ڼ� = ����"<<endl;
		break;
	case 'a':
		waist = true;
		cout << "����� �ڼ� = �㸮(����)"<<endl;
		break;
	case 's':
		mid = true;
		cout << "����� �ڼ� = �ߴ�"<<endl;
		break;
	case 'd':
		reversewaist = true;
		cout << "����� �ڼ� = �㸮(������)"<<endl;
		break;
	case 'x':
		sonmoc = true;
		cout << "����� �ڼ� = �ո� ġ��"<<endl;
		break;
	}


	if (attack == true) {
		if (leftup == true) {
			comstance();
			if (comleftup == true) {
				attack = false;
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
				attack = false;
			}

			else if (commid == true) {
				attack = false;
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
				cout << "�ߴ� ������ ������ �Ӹ� �������Ͽ����ϴ�."<<endl;
				cout << "10~15������"<<endl;
				Damage(3);
			}
			else {
				cout << "�Ӹ����ݿ� �����߽��ϴ�." << endl;
				cout << "��뿡�� 40~45�� �������� �־����ϴ�."<<endl;
				comDamage(1);
			}
			initcomstance();
			initstance();
		}
		else if (up == true) {
			cout << "��� �ڼ������� ���ݱ��� ������ �����Ͽ� Ű�� �ѹ� �� ������ ��Ģ���� ������ �� �� �ֽ��ϴ�."<<endl;
			cout << "���� ����� �Ӹ� ������ ����� �� �ֽ��ϴ�."<<endl;
			comstance();
			if (comleftup == true || comrigetup == true) {
				cout << "�� �����߽��ϴ�."<<endl;
			}
			else if (commid) {
				cout << "����� �ڼ��� �ߴ��Դϴ�." << endl;
				cout << "�������� �����ϴ�."<<endl;
			}
			else {
				cout << "�㸮���ݿ� ���߽��ϴ�."<<endl;
				cout << "25~30������"<<endl;
				Damage(2);
			}
			initcomstance();
			
			stance = 'm';
			cout <<endl<< "���� ����ڼ� �Դϴ�. ���� �ڼ��� ����ּ���(��ܼ� �ڿ��� ���ݷ��� ����մϴ�.)" << endl;
			cout << "(��ܼ��� �ٽ� ������ �� �����ϴ�.)"<<endl;
			cin >> stance;
			switch (stance) {
			case 'q':
				leftup = true;
				cout << "����� �ڼ� = �»��"<<endl;
				break;
			case 'w':
				up = true;
				cout << "�� ���� �������� �����"<<endl;
				cout << "�� �� �� �Ѿ ����"<<endl;
				break;
			case 'e':
				rigetup = true;
				cout << "����� �ڼ� = ����"<<endl;
				break;
			case 'a':
				waist = true;
				cout << "����� �ڼ� = �㸮(����)"<<endl;
				break;
			case 's':
				mid = true;
				cout << "����� �ڼ� = �ߴ�"<<endl;
				break;
			case 'd':
				reversewaist = true;
				cout << "����� �ڼ� = �㸮(������)"<<endl;
				break;
			}
			comstance();
			if (leftup) {
				if (comleftup) {
					cout << "������ �������ϴ�."<<endl;
				}
				else if (commid) {
					cout << "�ߴܻ����� ������ �Ӹ������� �߽��ϴ�"<<endl;
					cout << "������10~15 ������"<<endl;
					Damage(3);
				}
				else {
					cout << "�Ӹ����ݿ� �����߽��ϴ�."<<endl;
					cout << "��ܼ� ���� ������ �߰� �������� ���ϴ�."<<endl;
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
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
				attack = false;
			}

			else if (commid == true) {
				attack = false;
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
				cout << "�ߴ� ������ ������ �Ӹ� �������Ͽ����ϴ�."<<endl;
				cout << "������10~15������"<<endl;
				Damage(3);
				
			}
			else {
				cout << "�Ӹ����ݿ� �����߽��ϴ�."<<endl;
				cout << "��뿡�� 40~45�� �������� �־����ϴ�."<<endl;
				cout << "���� ����� ü�� = " << comenergy<<endl;
				comDamage(1);
			}
			initcomstance();
			initstance();
		}
		else if (waist == true) {
		comstance();
		if (comwaist == true) {
			attack = false;
			cout << "������ ����!"<<endl;
			cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
			attack = false;
		}

		else if (commid == true) {
			attack = false;
			cout << "������ ����!"<<endl;
			cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
			cout << "�ߴ� ������ ������ �㸮 �������Ͽ����ϴ�."<<endl;
			cout << "������10~15������"<<endl;
			Damage(3);
			
		}
		else {
			cout << "�㸮���ݿ� �����߽��ϴ�."<<endl;
			cout << "��뿡�� 25~30�� �������� �־����ϴ�."<<endl;
			comDamage(2);
		}
		initcomstance();
		initstance();
}
		else if (reversewaist == true) {
		comstance();
		if (comreversewaist == true) {
			attack = false;
			cout << "������ ����!"<<endl;
			cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
			attack = false;
		}

		else if (commid == true) {
			attack = false;
			cout << "������ ����!"<<endl;
			cout << "���ݱ��� �Ѿ���ϴ�."<<endl;
			cout << "�ߴ� ������ ������ �㸮 �������Ͽ����ϴ�."<<endl;
			cout << "������10~15������"<<endl;
			Damage(3);
		}
		else {
			cout << "�㸮���ݿ� �����߽��ϴ�."<<endl;
			cout << "��뿡�� 25~30�� �������� �־����ϴ�."<<endl;
			Damage(2);
		}
		initcomstance();
		initstance();
}
		else if (mid == true) {
		comstance();
		if (commid == true) {
			cout << "���� �ߴ��Դϴ�."<<endl;
			cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�."<<endl;
		}
		else if (comsonmoc == true) {
			cout << "�ո� ������ �¾ҽ��ϴ�."<<endl;
			cout << "������ 25~30"<<endl;
			Damage(2);
		}
		else {
			cout << "������ �ߴܻ��¿� ������ ���߽��ϴ�"<<endl;
			cout << "���濡�� ������ 10~15"<<endl;
			comDamage(3);
		}
		initcomstance();
		initstance();
}
		else if (sonmoc == true) {
		comstance();
		if (commid == true) {
			cout << "������ �ߴ��Դϴ�."<<endl;
			cout << "�ո� ������ �����߽��ϴ�."<<endl;
			Damage(2);
		}
		else if (comsonmoc == true) {
			cout << "������ �������ϴ�"<<endl;
			cout << "���ݱ��� �Ѿ�ϴ�"<<endl;
			attack = false;
		}
		else {
			cout << "���濡�� ������ �¾ҽ��ϴ�."<<endl;
			cout << "25~30�� ������"<<endl;
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
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ�Խ��ϴ�."<<endl;
				attack = true;
			}

			else if (commid == true) {
				cout << "���ϸ�... ��ı��.(��밡 ����)"<<endl;
				cout << "���ݱ��� �����Խ��ϴ�"<<endl;
				attack = true;
			}
			else {
				cout << "���ݿ� ���߽��ϴ�."<<endl;
				cout << "25~30�� �������� �޽��ϴ�."<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (up == true) {
			cout << "��� ������ ���ݱ��� ������ �����Ͽ� Ű�� �ѹ� �� ������ ��Ģ���� ������ �� �� �ֽ��ϴ�."<<endl;
			cout << "���� ����� �Ӹ� ������ ����� �� �ֽ��ϴ�."<<endl;
			comstance();
			if (comleftup == true || comrigetup == true) {
				cout << "�� �����߽��ϴ�."<<endl;
			}
			else if (commid) {
				cout << "����� �ڼ��� �ߴ��Դϴ�."<<endl;
				cout << "�������� �����ϴ�."<<endl;
			}
			else {
				cout << "�㸮���ݿ� ���߽��ϴ�."<<endl;
				cout << "25~30������"<<endl;
				Damage(2);
			}
			initcomstance();
			comstance();
			cout << "���� ����ڼ� �Դϴ�. ���� �ڼ��� ����ּ���(��ܼ� �ڿ��� ���ݷ��� ����մϴ�.)"<<endl;
			cout << "(��ܼ��� �ٽ� ������ �� �����ϴ�.)"<<endl;
			cin >> stance;
			switch (stance) {
			case 'q':
				leftup = true;
				cout << "����� �ڼ� = �»��"<<endl;
				break;
			case 'w':
				up = true;
				cout << "�� ���� �������� �����"<<endl;
				cout << "�� �� �� �Ѿ ����"<<endl;
				break;
			case 'e':
				rigetup = true;
				cout << "����� �ڼ� = ����"<<endl;
				break;
			case 'a':
				waist = true;
				cout << "����� �ڼ� = �㸮(����)"<<endl;
				break;
			case 's':
				mid = true;
				cout << "����� �ڼ� = �ߴ�"<<endl;
				break;
			case 'd':
				reversewaist = true;
				cout << "����� �ڼ� = �㸮(������)"<<endl;
				break;
			}
			if (leftup) {
				if (comleftup) {
					cout << "������ �������ϴ�."<<endl;
				}
				else if (commid) {
					cout << "�ߴܻ����� ������ �Ӹ������� �߽��ϴ�"<<endl;
					cout << "10~15 ������"<<endl;
					Damage(3);
				}
				else {
					cout << "�Ӹ����ݿ� �����߽��ϴ�."<<endl;
					cout << "��ܼ� ���� ������ �߰� �������� ���ϴ�."<<endl;
					comDamage(4);
				}
				initstance();
			}

		}
		else if (rigetup == true) {
			comstance();
			if (comrigetup == true) {
				attack = false;
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ�Խ��ϴ�."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "���ϸ�...��īŸ...(��밡 ����)"<<endl;
			}
			else {
				cout << "���ݿ� ���߽��ϴ�."<<endl;
				cout << "��뿡�� 25~30�� �������� �޾ҽ��ϴ�."<<endl;
				comDamage(2);
			}
			initcomstance();
			initstance();
		}
		else if (waist == true) {
			comstance();
			if (waist == true) {
				attack = false;
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ�ɴϴ�."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "���ϸ�.......��īŸ!!!!!!!  (��밡 ����)"<<endl;
			}
			else {
				cout << "���ݿ� ���߽��ϴ�"<<endl;
				cout << "25~30������"<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (reversewaist == true) {
			comstance();
			if (comreversewaist == true) {
				cout << "������ ����!"<<endl;
				cout << "���ݱ��� �Ѿ�Խ��ϴ�."<<endl;
				attack = true;
			}

			else if (commid == true) {
				attack = false;
				cout << "���ϸ�...��ıŸ(��밡 ����)"<<endl;
			}
			else {
				cout << "�㸮���ݿ� �����߽��ϴ�."<<endl;
				cout << "��뿡�� 25~30�� �������� �־����ϴ�."<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
		else if (mid == true) {
			comstance();
			if (commid == true) {
				cout << "���� �ߴ��Դϴ�."<<endl;
				cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�."<<endl;
			}
			else if (comsonmoc == true) {
				cout << "�ո� ������ �¾ҽ��ϴ�."<<endl;
				cout << "������ 25~30"<<endl;
				Damage(2);
			}
			else {
				cout << "������ �ߴܻ��¿� ������ ���߽��ϴ�"<<endl;
				cout << "���濡�� ������ 10~15"<<endl;
				comDamage(3);
			}
			initcomstance();
			initstance();
		}
		else if (sonmoc == true) {
			comstance();
			if (commid == true) {
				cout << "������ �ߴ��Դϴ�."<<endl;
				cout << "�ո� ������ �����߽��ϴ�."<<endl;
				Damage(2);
			}
			else if (comsonmoc == true) {
				cout << "������ ���ҽ��ϴ�"<<endl;
				cout << "���ݱ��� �Ѿ�ɴϴ�"<<endl;
				attack = true;
			}
			else {
				cout << "���濡�� ������ �¾ҽ��ϴ�."<<endl;
				cout << "25~30�� ������"<<endl;
				Damage(2);
			}
			initcomstance();
			initstance();
		}
	}

}
Game::Game()
{
	cout << "���� ����"<<endl;
	cout << "q = �»��, w = ���, e = ����" << endl;
	cout << "a = �㸮  , s = �ߴ�, d = ���㸮" << endl;
	cout << "            x = �ո�" << endl<<endl;
	cout << "���ݱ��� �ִ� ���·� �����ϸ� ������ ���� �ڼ��� �������� ���ݱ��� �Ѿ�ų� �Ѿ�ɴϴ�." << endl;
	cout << "�ߴܻ����� ������ ������ �ϸ� ������ �������� �Խ��ϴ�." << endl;
	cout << "�ߴܻ����� ���� �ո����θ� ������ �� �ֽ��ϴ�.";
	cout << "w(���)�ڼ��� ��� �Ӹ� ������ ����� �� ������ ���ϵ��� ������ �� �����ϴ�." << endl;
	cout << "��� ���������� ���ݷ��� �����մϴ�." << endl;
	do 
	{
		battle();
	} while (life!=0);


}