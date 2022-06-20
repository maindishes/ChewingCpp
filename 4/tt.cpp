#include <iostream>
#include <string>
int main()
{
	std::string str1="test";

	std::string &str2= str1;

	std::cout << str2 << std::endl;
}

