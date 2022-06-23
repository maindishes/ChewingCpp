#include <iostream>

class Animal
{
	public:
		Animal() {} 
		virtual ~Animal() {}
		virtual void speak() = 0;
};

class Dog : public Animal
{
	public:
		Dog() : Animal() {}
		void speak() {std::cout << "wall wall" << std::endl;}
};


class Cat : public Animal
{
	public:
		Cat(): Animal() {}
		void speak() { std::cout << "mewow mewow" <<std::endl;}
};

int main()
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	
	Dog d1; 
	d1.speak();	
	dog->speak();
	cat->speak();
}

