#include <iostream>
using namespace std;

class Date
{
private:
	int year, month, day;
public:
	void SetDate(int ,int ,int);
	void Dateprint();
	bool Leap(int);
	bool Datejudge(int, int, int);
	void add_a_day();
};

void Date::SetDate(int year_, int month_, int day_)
{
	if (Datejudge(year_, month_, day_))
	{
		year = year_;
		month = month_;
		day = day_;
	}
}

void Date::Dateprint()
{
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::Datejudge(int year_, int month_, int day_)
{
	int daylimit = 31;
	if (year_ < 1 || month_ > 12 || month_ < 1 || day_ < 1)
		return false;
	switch (month_)
	{
	case 4:
	case 6:
	case 9:
	case 11:daylimit--; break;
	case 2:daylimit = Leap(year_) ? 29 : 28; break;

	}
		return day_ <= daylimit;
}

bool Date::Leap(int year_)
{
	if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	Date d1;
	int year, day, month;
	cin >> year >> month >> day;
	d1.SetDate(year, month, day);
	d1.Dateprint();

	return 0;
}
