#include <iostream>
#include <iomanip>
class Marine
{
	private:
		int hp;
		int coord_x, coord_y;
		int damage;
		bool is_dead;
		char *name;
	
	public:
		Marine();
		Marine(int x, int y, const char* m_name);
		Marine(int x, int y);
		~Marine();
		int attack();
		void be_attacked(int damaged);
		void move(int x, int y);

		void show_status();
};

Marine::Marine()
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* m_name)
{
	name = new char[strlen(m_name)+1];
	strcpy(name, m_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage =5;
	is_dead = false;
}

Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage =5;
	is_dead = false;
	name = NULL;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{
	return damage;
}

void Marine::be_attacked(int damaged)
{
	hp -= damaged;
	if (hp <= 0)
		is_dead = true;
}

void Marine::show_status()
{
	std::cout <<std::setw(10) << " *** Marine *** " << std::endl;
	std::cout << " Name    :" << name << std::endl;
	std::cout << " Locatin : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout <<" HP : " << hp << std::endl;
}
Marine::~Marine()
{
	std::cout << name << " 의 소멸자 자동 호출 !" << std::endl;
	if (name != NULL)
	{
		delete[] name;
	}
}
int main()
{
	Marine*  marines[100];
	
	
	marines[0] = new Marine(2,3, "keokim 1");
	marines[1] = new Marine(3,5,"junyopar 1");

	marines[0]->show_status();
	marines[1]->show_status();
	
	std::cout << std::endl << "마린 1 이 마린 2 공격 ! " << std:: endl;
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}


