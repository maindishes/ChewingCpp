#include <iostream>

class myString
{
	private:
		char* string_content;
		int string_len;
	public:
		myString(char c); // 문자 하나로 생성
		myString(const char *str); // 문자열로 부터 생성
		myString(const myString& str); // 복사생성자
		~myString();
		//
		int len() const;
		void print() const;
		void println() const;
};

////


myString::myString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_len = 1;
}

myString::myString(const char *str)
{
	string_len = strlen(str);
	std::cout << "TEST----- : ";
	std::cout << string_len << std::endl;
	string_content = new char[string_len];

	for (int i=0; i != string_len; i++)
		string_content[i]=str[i];
}

myString::myString(const myString& str)
{
	string_len = str.string_len;
	string_content = new char[string_len];
	for (int i=0; i!= string_len; i++)
		string_content[i]=str.string_content[i];}

myString::~myString()
{
	delete[] string_content;
}

////

int myString::len() const {return string_len;}

void myString::print() const
{
	for (int i=0; i!= string_len; i++)
	{
		std::cout<< string_content[i];
	}
}

void myString::println() const
{
	for (int i=0; i!= string_len; i++)
	{
		std::cout<< string_content[i];
	}
	std::cout << std::endl;
}


int main()
{
	myString str1("hello World!");
	std::cout << "1--------" << "\n";
	myString str2(str1);

	std::cout << "2--------" << "\n";
	str1.println();
	std::cout << "3--------" << "\n";
	str2.println();
}





