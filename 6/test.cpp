#include <iostream>

class Test
{
	private:
		int n;
	public:
		Test() :n(10) {} 
		int &getN(void) { return this->n; }
};

int main()
{
	Test test;
	test.getN()++;
	std::cout << test.getN() << std::endl;
}

