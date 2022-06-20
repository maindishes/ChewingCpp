#include <iostream>

class Date
{
	int year_;
	int month_;
	int day_;

	public:
		void SetDate(int year, int month, int date);
		void ShowDate();
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);
		Date()
		{
			year_ = 2022;
			month_ = 6;
			day_ = 3;
		}
};

void Date::SetDate(int year, int month, int date)
{
	year_ = year;
	month_ = month;
	day_ = date;
}

void Date::ShowDate()
{
	std::cout << year_ << "년 " << month_ << "월 " << day_ << "일 " << "\n";
}
void Date::AddYear(int inc)
{
	year_ += inc;
}
void Date::AddMonth(int inc)
{
	month_ += inc;
	if (month_ >= 13)
	{
		//std::cout << "TEST: "<< month_ % 12 << "\n";
		//std::cout << month_ / 12 << "\n";
		year_ += month_ / 12;
		month_ = month_ % 12;
	}
}
void Date::AddDay(int inc)
{
	int sdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	//int ssdays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	//int temp[];
	day_ += inc;
	int curr;
	curr = month_ -1;
	if (day_ >= 365)
	{
		year_ += day_ / 365;
		day_ = day_ % 365;
	}
	if (year_ % 4 == 0 && year_ % 100 != 0)
		sdays[1]=29;
	while (1)
	{
		std::cout <<"TEST : " << sdays[curr] << " " << day_ << "\n";
		if (sdays[curr] < day_)
		{
			day_ -= sdays[curr];
			curr++;
			if (curr == 12)
				curr = 0;
			AddMonth(1);
		}
		else if (sdays[curr] >= day_)
		{
			break;
		}
	}
}
int main()
{
	Date date = Date();
	//date.SetDate(2011,3,1);
	date.ShowDate();

	date.AddDay(30);
	date.ShowDate();

	date.AddDay(2000);
	date.ShowDate();

	Date date2;
	date2.AddDay(29);
	date2.ShowDate();

	Date date3();
	date3.SetDate(2012,8,4);
	date3.AddDay(2500);
	date3.ShowDate();
}

