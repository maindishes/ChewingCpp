#include <iostream>

void	print(int x) { std::cout << "int  : " << x << "\n";}
//void	print(char x){ std::cout << "char : " << x << "\n";}
void	print(char x){ std::cout << "double : "<<x<<"\n";}


int main()
{
	int a =1;
	char b = 'A';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);
	return 0;
}

