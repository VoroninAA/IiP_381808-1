#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(const Date & _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
}
Date::Date(int _day, int _month, int _year) {
	day = _day;
	month = _month;
	year = _year;
}
void Date::SetDate(int _day, int _month, int _year) {
	day = _day;
	month = _month;
	year = _year;
}
void Date::GetDate(int & _day, int & _month, int & _year) const {
	_day = day;
	_month = month;
	_year = year;
}
int Date::GetDay()
{
	return day;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetYear()
{
	return year;
}
Date & Date::operator=(const Date & _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
	return *this;

}
bool Date::operator==(const Date & _date)
{
	if (day == _date.day&&month == _date.month&&year == _date.year)
		return true;
	else return false;
}
Date::~Date()
{
	day = 0;
	month = 0;
	year = 0;
}

std::ostream & operator<<(std::ostream & stream, const Date & _f)
{
	stream << _f.day << ' ' << _f.month << ' ' << _f.year << ' ';
	return stream;
}

std::istream & operator>>(std::istream & stream, Date & _f)
{
	stream >> _f.day >> _f.month >> _f.year;
	return stream;
}
