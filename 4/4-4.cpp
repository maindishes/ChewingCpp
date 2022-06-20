#include <iostream>
#include <iomanip>
class Marine
{
	private:
		static int total_num;
		int hp;
		int coord_x, coord_y;
		const int default_damage;
		bool is_dead;
		char *name;
	
	public:
		Marine();
		Marine(int x, int y, const char* m_name);
		Marine(int x, int y);
		~Marine();
		int attack() const;
		Marine&  be_attacked(int damaged);
		void move(int x, int y);

		void show_status();
		static void show_total_marine();
};
int Marine::total_num = 0;
void Marine::show_total_marine()
{
	std::cout << " 전체 마린 수 : " << total_num << std::endl;
}

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), default_damage(5),is_dead(false) 
{
	total_num++;
}

//Marine::Marine()
//{
//	hp = 50;
//	coord_x = coord_y = 0;
//	damage = 5;
//	is_dead = false;
//	name = NULL;
//}

//Marine::Marine(int x, int y, const char* m_name)
//{
//	name = new char[strlen(m_name)+1];
//	strcpy(name, m_name);
//
//	coord_x = x;
//	coord_y = y;
//	hp = 50;
//	//default_damage =5;
//	is_dead = false;
//}
Marine::Marine(int x, int y, const char* m_name)
	:coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) 
{
	name = new char [strlen(m_name)+1];
	strcpy(name,m_name);
	total_num++;
}
//Marine::Marine(int x, int y)
//{
//	std::cout << "TEST 생성자 + 대입" << "\n"; 
//	coord_x = x;
//	coord_y = y;
//	hp = 50;
//	damage =5;
//	is_dead = false;
//	name = NULL;
//}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack() const
{
	return default_damage;
}

Marine& Marine::be_attacked(int damaged)
{
	hp -= damaged;
	if (hp <= 0)
		is_dead = true;
	return *this;
}

void Marine::show_status()
{
	std::cout <<std::setw(10) << " *** Marine *** " << std::endl;
	std::cout << " Name    :" << name << std::endl;
	std::cout << " Locatin : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout <<" HP : " << hp << std::endl;
	std::cout <<" 총 마린수  : " << total_num <<std::endl;
}
Marine::~Marine()
{
	std::cout << name << " 의 소멸자 자동 호출 !" << std::endl;
	if (name != NULL)
	{
		delete[] name;
	}
	total_num--;
}
int main()
{
	Marine*  marines[100];
	
	Marine::show_total_marine();	
	marines[0] = new Marine(2,3, "keokim 1");
	marines[1] = new Marine(3,5,"junyopar 1");

	Marine::show_total_marine();	
	marines[0]->show_status();
	marines[1]->show_status();
	marines[2] = new Marine(2,3, "jihoh 1");	
	std::cout << std::endl << "마린 1 이 마린 2 공격 ! " << std:: endl;
	marines[1]->be_attacked(marines[0]->attack()).be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();
	marines[2]->show_status();
	delete marines[0];
	delete marines[1];
	delete marines[2];
	Marine::show_total_marine();	
}


