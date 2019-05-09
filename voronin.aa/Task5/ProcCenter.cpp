#include "ProcCenter.h"



ProcCenter::ProcCenter()
{
	bankID = 0;
	amount = 0;
	password = "";
	
}

ProcCenter::ProcCenter(const ProcCenter & _pc)
{
	bankID = _pc.bankID;
	amount = _pc.amount;
	password = _pc.password;
	depozitinfo = _pc.depozitinfo;
	fio = _pc.fio;
}


ProcCenter::~ProcCenter()
{
	bankID = 0;
	amount = 0;
	password = "";
	
	
}

std::ostream & operator<<(std::ostream & stream, ProcCenter & _f)
{
	stream << _f.bankID << ' ' << _f.amount << ' '
		<< _f.depozitinfo << ' ' << _f.fio <<_f.password;
	return stream;
}

std::istream & operator>>(std::istream & stream, ProcCenter & _f)
{
	stream >> _f.bankID >> _f.amount >> _f.depozitinfo >> _f.fio >> _f.password;
	return stream;
}
