#include <iostream>

class Animal
{
	private:
		int food;
		int weight;

	public:
		void set_animal(int _food, int _weight)
		{
			food = _food;
			weight = _weight;
		}
		void increase_food(int inc)
		{
			food += inc;
			weight += (inc / 3);
		}

		void view_stat()
		{
			std::cout << " 이 동물의 food  : " << food << "\n";
			std::cout << " 이 동물의 weight: " << weight << "\n";
		}
};

int main()
{
	Animal animal;
	int a, b, c;
	std::cin >> a >> b >> c;
	// 100 50 30 
	animal.set_animal(a, b);
	animal.increase_food(c);
	animal.view_stat();
	animal.food -= 10;
	return 0;
}

