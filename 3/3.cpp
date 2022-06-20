#include <iostream>

using namespace std;
//int	main()
//{
//	int arr_size;
//	cout << "arry size : "; 
//	cin >> arr_size;
//	int *list = new int[arr_size];
//	for (int i = 0 ; i < arr_size; i++)
//	{
//		cin >> list[i];
//	}
//	for (int i = 0; i < arr_size; i++)
//	{
//		cout << "[ " << list[i] << " ]";
//	}
//	cout << "\n";
//	delete[] list;
//	return 0;
//}
//


//int main()
//{
//	int a = 1;
//	if (a == 1)
//	{
//		cout << "외부 변수 1" << a << "\n";
//		int a = 3;
//		cout << "내부 변수 " << a << "\n";
//	}
//	cout <<" 외부 변수 2" << a << "\n";
//}
//


typedef struct Animal
{
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
} Animal;

void	create_animal(Animal *animal)
{
	cout << " animal name? :";
	cin >> animal->name;

	cout << " animal age?  :";
	cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void	play(Animal *animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -=20;
}

void	show_stat(Animal *animal)
{
	cout << animal->name << "의 상태 " << "\n";
	cout << " health : " << animal->health << "\n";
	cout << " food   : " << animal->food << "\n";
	cout << " clean  : " << animal->clean << "\n";
}

void	one_day_pass(Animal *animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

int main()
{
	Animal *list[10];
	int animal_count = 0;

	while (1)
	{
		cout << "1. animal append" << "\n";
		cout << "2. animal play" << "\n";
		cout << "3. show status" << "\n";

		int input;
		cin >> input;
		if (cin.eof())
			break;

		switch (input)
		{
			int play_with;
			case 1:
				list[animal_count] = new Animal;
				create_animal(list[animal_count]);

				animal_count++;
				break;

			case 2:
				cout << " play who ? : ";
				cin >> play_with;

				if (play_with < animal_count) 
					play(list[play_with]);
				break;
			case 3:
				cout << " show who ? : ";
				cin >> play_with;
				if (play_with < animal_count)
					show_stat(list[play_with]);
				break;
		}
	}

	for (int i =0; i != animal_count; i++)
	{
		delete list[i];
	}
}



		

