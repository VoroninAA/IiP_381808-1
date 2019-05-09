#pragma once
#include<fstream>
// Вспомогательный класс дата
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(const Date& _date);
	Date(int _day, int _month, int _year);
	void SetDate(int _day, int _month, int _year); // Установить дату
	void GetDate(int & _day, int & _month, int & _year) const; // Узнать дату
	int GetDay();
	int GetMonth();
	int GetYear();
	Date& operator=(const Date& _date);
	bool operator==(const Date& _date);
	~Date();

	friend std::ostream& operator<<(std::ostream& stream, const Date& _f);
	friend std::istream& operator>>(std::istream& stream, Date& _f);
};

