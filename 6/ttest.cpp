#include <iostream> 
int Add( int num1,  int num2) // const 참조자형 매개변수
{
	return num1 + num2;
} 
int main(void)
{	
	int num1 = 1;
	int num2 = 2;
	std::cout << Add(num1, num2) << std::endl; // 상수를 전달        
	return 0;
}
