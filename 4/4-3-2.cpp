#include <string>
#include <iostream>

class Photon
{
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	char *name;

	public:
		Photon(int x, int y);
		Photon(int x, int y, const char *p_name);
		Photon(const Photon& pc);
		~Photon();		
		void show_status();
};

Photon::Photon(int x, int y, const char *p_name)
{
	name = new char[strlen(p_name)+1];
	strcpy(name,p_name);

	std::cout << "생성자 호출 ! " << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

Photon::Photon(const Photon& pc)
{
	name = new char[strlen(pc.name)+1];
	strcpy(name,pc.name);

	std::cout << "복사 생성자 호출 ! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

void Photon::show_status()
{
	std::cout << "Photon Cannon " << std::endl;
	std::cout << "Photon Name   : " << name << std::endl;
	std::cout << "Location      : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
}
Photon::~Photon()
{
	std::cout << " 소멸생성자 호출! "<< std::endl;
	if (name)
		delete[] name;
}
int main()
{
	Photon pc1(3,3 ,"keokim");
	Photon pc2(pc1);
	Photon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();
	pc3.show_status();


}
