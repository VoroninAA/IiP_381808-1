#include "FloorScales.h"

FloorScales::FloorScales()
{
	
	size = 0;
	amount = 0;
	currentuser = "";
}	
FloorScales::FloorScales(const FloorScales & _f)
{
	size = _f.size;
	amount = _f.amount;
	currentuser = _f.currentuser;
	user = _f.user;
	collection = _f.collection;

}
FloorScales::~FloorScales()
{
	size = 0;
	amount = 0;
	currentuser = "";
}
void FloorScales::AddUser(std::string _user)
{
	amount += 1;
	user.Add(_user);
}
void FloorScales::SetUser(int _usernumber)
{
	currentuser = user[_usernumber];
}
Date FloorScales::GetFirstdate()
{
	for (int i = 0; i < size; i++) {
		if (collection[i].GetUser() == currentuser)
			return collection[i].date;
	}
	Date wrong(-1, -1, -1);
	return wrong;
}
void FloorScales::Add( int _day, int _month, int _year, double _weight)
{
	
	size += 1;
	Collection tmp;
	tmp.date.SetDate(_day, _month, _year);
	tmp.SetUser(currentuser);
	tmp.SetWeight( _weight);
	for (int i = 0; i < size; i++) {
		if (collection[i].date == tmp.date&& collection[i].GetUser() == tmp.GetUser())
			collection[i].SetWeight(_weight);
		else collection.Add(tmp);
	}
	
}
double FloorScales::GetWeight(int _day, int _month, int _year)
{
	Date tmp(_day,_month,_year);
	for (int i = 0; i < size; i++)
		if (collection[i].GetUser() == currentuser && collection[i].date == tmp)
			return collection[i].GetWeight();
	return -1;
}

double FloorScales::FindMediumWeight(int _day, int _month, int _year)
{
	double sum=0;
	int count=0;
	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()&&_month == collection[i].date.GetMonth()&& _year == collection[i].date.GetYear()) {
			sum += collection[i].GetWeight();
			count += 1;
		}
	}
	if (sum == 0 && count == 0)
		return 0;
	return (sum/count);
}

double FloorScales::FindMediumWeightAll(std::string& str)
{
	Date first, second;
	bool tag=false;
	double sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()) {
			if (tag == false) {
				tag = true;
				first = collection[i].date;
			}
			sum += collection[i].GetWeight();
			count += 1;
			second = collection[i].date;
		}
	}
	
	str += std::to_string(first.GetDay());
	str += std::to_string(first.GetMonth());
	str +=std::to_string( first.GetYear());
	str += '-';
	str += std::to_string(second.GetDay());
	str += std::to_string(second.GetMonth());
	str += std::to_string(second.GetYear());
	if (sum == 0 && count == 0)
		return 0;
	return (sum / count);
}

double FloorScales::FindMinWeight(int _day, int _month, int _year)
{
	double min = 10000;

	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()&&_month == collection[i].date.GetMonth()&& _year == collection[i].date.GetYear()) {
			if (min > collection[i].GetWeight())
				min = collection[i].GetWeight();
		}
	}

	return min;
}

double FloorScales::FindMinWeightAll(std::string& str)
{
	double min = 10000;
	Date first, second;
	bool tag = false;

	
	
	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()) {
			if (tag == false) {
				tag = true;
				first = collection[i].date;
			}
			if (min > collection[i].GetWeight())
				min = collection[i].GetWeight();
			second = collection[i].date;
		}
	}
	str += std::to_string(first.GetDay());
	str += std::to_string(first.GetMonth());
	str += std::to_string(first.GetYear());
	str += '-';
	str += std::to_string(second.GetDay());
	str += std::to_string(second.GetMonth());
	str += std::to_string(second.GetYear());
	return min;
}

double FloorScales::FindMaxWeight(int _day, int _month, int _year)
{
	double max = -1;

	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()&&_month == collection[i].date.GetMonth()&& _year == collection[i].date.GetYear()) {
			if (max < collection[i].GetWeight())
				max = collection[i].GetWeight();
		}
	}

	return max;
}

double FloorScales::FindMaxWeightAll(std::string& str)
{
	double max =-1;
	Date first, second;
	bool tag = false;



	for (int i = 0; i < size; i++) {
		if (currentuser == collection[i].GetUser()) {
			if (tag == false) {
				tag = true;
				first = collection[i].date;
			}
			if (max < collection[i].GetWeight())
				max = collection[i].GetWeight();
			second = collection[i].date;
		}
	}
	str += std::to_string(first.GetDay());
	str += std::to_string(first.GetMonth());
	str += std::to_string(first.GetYear());
	str += '-';
	str += std::to_string(second.GetDay());
	str += std::to_string(second.GetMonth());
	str += std::to_string(second.GetYear());

	return max;
}

std::ostream & operator<<(std::ostream & stream, const FloorScales & _f)
{
	stream << _f.amount << ' ';
	for (int i = 0; i < _f.amount; i++)
		stream << _f.user[i] << ' ';
	stream << _f.size << ' ';
		for (int i = 0; i < _f.size; i++)
			stream << _f.collection[i] << ' ';
		return stream;
}

std::istream & operator>>(std::istream & stream, FloorScales & _f)
{
	Collection tmp;
	std::string str;
	stream >> _f.amount;
	for (int i = 0; i < _f.amount; i++) {
		stream >> str;
		_f.user.Add(str);
	}
	stream >> _f.size;
	for (int i = 0; i < _f.size; i++) {
		stream >> tmp;
		_f.collection.Add(tmp);
	}
	return stream;
}
