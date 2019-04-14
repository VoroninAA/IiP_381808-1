#include "Collection.h"



Collection::Collection()
{
	user = "";
	date.SetDate(0,0,0);
	weight = 0;
}

Collection::Collection(std::string _user)
{
	user = _user;
	date.SetDate(0, 0, 0);
	weight = 0;
}

Collection::Collection(const Collection & _c)
{
	user = _c.user;
	date = _c.date;
	weight = _c.weight;
}



Collection::~Collection()
{
	
	user = "";
	date.SetDate(0, 0, 0);
	weight = 0;
}

double Collection::GetWeight()
{
	return weight;
}

std::string Collection::GetUser()
{
	return user;
}

void Collection::SetUser(std::string str)
{
	user = str;
	return;
}

void Collection::SetWeight(double w)
{
	weight = w;
	return;
}


Collection & Collection::operator=(const Collection & _collection)
{
	
	user = _collection.user;
	weight = _collection.weight;
	date = _collection.date;
	return *this;
}

std::ostream & operator<<(std::ostream & stream, const Collection & _f)
{
	stream << _f.user << ' ' << _f.weight << ' ' << _f.date  <<' ';
	return stream;

}

std::istream & operator>>(std::istream & stream, Collection & _f)
{
	stream >> _f.user >> _f.weight >> _f.date;
	return stream;
}
