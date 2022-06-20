#include <iostream>
int&	function(int& a)
{
	a = 5;
	return a;
}

int main()
{
	int b = 2;
	int c = function(b);
	std::cout << b << "\n" << c <<"\n";
	b = 3;
	return 0;
}

