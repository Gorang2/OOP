#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Avengers {
	public:
		Avengers() {
			name = "";
			attack_point = 0;
			defense_point = 0;
			health = 0;
		}
		~Avengers() {}
// 캐릭터 설정 함수
		virtual void set(string _name, int _attack, int _defense, int _health) {}
// 공격 함수
		virtual int attack() { return 0; }
// 방어 함수
		virtual void defense(int _attack_point) { }
	// 캐릭터 정보 출력 함수
		virtual void print_info() { }
	protected:
		string name; // 캐릭터 이름
		int attack_point; // 공격력
		int defense_point; // 방어력
		int health; // 체력
};

class Character : public Avengers {
	public:
		Character(): Avengers::Avengers() {}
		~Character() {}
		string CharacterList[3] = {"IronMan", "CaptainAmerica", "Thor"};
		void set(string _name, int _attack, int _defense, int _health)
		{
			name = _name;
			attack_point = _attack;
			defense_point = _defense;
			health = _health;
		}
		int get_health() { return health; }
		int getAttackPoint() { return attack_point; }
		void attacked(int damage)
		{ health -= (damage - defense_point); }
		void display()
		{
			cout << "Name: " << name << endl;;
			cout << "Attack_Point: " << attack_point << endl;
			cout << "Defense_Point: " << defense_point << endl;
			cout << "Health: " << health << endl;
		}
};

int main() {
	Character my_char;
	Character enemy_char;
	/* 구현 */
	srand(time(NULL));
	string my_name, enemy_name;
	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> my_name;
	enemy_name = enemy_char.CharacterList[rand() % 4];

	if (my_name == "IronMan" || enemy_name == "IronMan")
		my_name == "IronMan" ? my_char.set("IronMan", 70, 40, 100) : enemy_char.set("IronMan", 70, 40, 100);
	if (my_name == "CaptainAmerica" || enemy_name == "CaptainAmerica")
		my_name == "CaptainAmerica" ? my_char.set("CaptainAmerica", 60, 50, 100) : enemy_char.set("CaptainAmerica", 60, 50, 100);
	if (my_name == "Thor" || enemy_name == "Thor")
		my_name == "Thor" ? my_char.set("Thor", 80, 30, 100) : enemy_char.set("Thor", 80, 30, 100);
	cout << "--My Character--" << endl;
	my_char.display();
	cout << "--Enemy Character--" << endl;
	enemy_char.display();
	
	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
	 << "Enemy Life:" << enemy_char.get_health() << endl;
	while (1)
	{
		enemy_char.attacked(my_char.getAttackPoint());
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0)
		{
			cout << "You Win!" << endl;
			break;
		}
		my_char.attacked(enemy_char.getAttackPoint());
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0)
		{
			cout << "You Lose..." << endl;
			break;
		}
	}
	return 0;
}
