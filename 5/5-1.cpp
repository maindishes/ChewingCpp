#include <iostream>
#include <string>

class myString
{
	private:
		char* string_content;	// 문자열 데이터를 가리키는 포인터
		int string_len;      // 문자열 길이

		int memory_capacity; //현재 할당된 용량
	public:
		myString(char c); // 문자 하나로 생성
		myString(const char *str); // 문자열로 부터 생성
		myString(const myString& str); // 복사생성자
		~myString();
		//
		int len() const;
		int capacity() const;
		void reserve(int size);

		void print() const;
		void println() const;

		char at(int i) const;

		int compare(myString& str);       // 인자에 클래스 변수를 주석으로 넣어주는 의미 ?? 정확히 모름 -> 아마 복사생성해서 넣는다는 의미?
		bool operator==(myString& str);
};

////


myString::myString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_len = 1;
}

myString::myString(const char *str)
{
	string_len = strlen(str);
	//std::cout << "TEST----- : ";
	//std::cout << string_len << std::endl;
	memory_capacity = string_len;
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

int myString::capacity() const
{
	return memory_capacity;
}

void myString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char *prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i=0; i!= string_len; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려하는  size가 현재 capacity 보다 작다면 
	// 아무것도 안 해도 된다.
}

char myString::at(int i) const
{
	if (i>= string_len || i < 0)
		return 0;
	else
		return string_content[i];
}

int myString::compare(myString& str)
{
	// (*this) - (str) 을 수행해서 1,0,-1 로 그결과를 리턴한다.
	// 1은 (*this)가 사전식으로 더 뒤에 온다는 의미. 
	// 0은 두 문자열이 닽다는 의미 
	
	for (int i=0; i< std::min(string_len, str.string_len); i++)
	{
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}
	// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 같다는 것.
	// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.
	if (string_len == str.string_len)
		return 0;

	// abc , abcd의 크기는 abcd가 뒤에 오게 된다.
	else if (string_len > str.string_len)
		return 1;

	return -1;
}

bool myString::operator==(myString& str)
{
	return !compare(str);
}

int main()
{
	myString str1("a word");
	myString str2("aaaaaa");
	myString str3 = str2;

	if (str1 == str2)
		std::cout << "str1 str2 same" << std::endl;
	else
		std::cout << "str1 str2 diff" << std::endl;

	if (str2 == str3)
		std::cout << "str2 str3 same"<< std::endl;
	else
		std::cout << "str2 str3 diff"<<std::endl;
}



