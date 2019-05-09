#include"FIO.h"

FIO::FIO()
{
	name = "";
	surname = "";
	patronymic = "";
}

FIO::~FIO()
{
	name = "";
	surname = "";
	patronymic = "";
}

FIO & FIO::operator=(const FIO & _f)
{
	
	name = _f.name;
	surname = _f.surname;
	patronymic = _f.patronymic;
	return *this;
}

std::ostream & operator<<(std::ostream & stream,const FIO & _f)
{
	stream << _f.name <<' ' << _f.surname <<' ' << _f.patronymic <<' ';
	return stream;
}

std::istream & operator>>(std::istream & stream, FIO & _f)
{
	stream >> _f.name >> _f.surname >> _f.patronymic;
	return stream;
}
