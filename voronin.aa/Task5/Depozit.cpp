#include "Depozit.h"
#include<iostream>


Depozit::Depozit()
{
	userNumber = -1;
	ifauthorize = false;
}


Depozit::~Depozit()
{
	userNumber = -1;
	ifauthorize = false;
}

Depozit::Depozit(const Depozit & _d)
{
	userNumber = _d.userNumber;
	ifauthorize = _d.ifauthorize;
	database = _d.database;
}

void Depozit::LogIn(int _IDNumber, std::string _password)
{
	for (int i = 0; i < database.GetCount(); i++) {
		if (database[i].GetID() == _IDNumber) {
			if (database[i].GetPassword() == _password) {
				ifauthorize = true;
				userNumber = i;
			}
			else throw DepozitExeption("�������� ������!");
		}
	}
	if (userNumber == -1)
			throw DepozitExeption("������������� � ����� ID �� ������");
}

void Depozit::ShowInfo()
{
	std::cout << "��������� �������� ��������:" << std::endl << "1) 3 ������ ��� 5%"
		<< std::endl << "2) 6 ������� ��� 5,5% "
		<< std::endl << "3) 1 ��� ��� 6%"
		<< std::endl << "4) 2 ���� ��� 6.5%"
		<< std::endl << "5) 3 ���� ��� 7%"
		<< std::endl << "��������� ����:"
		<< std::endl << "1) �� 100 �.�"
		<< std::endl << "2) �� 100 �.�. �� 500 �.�   +0,5%"
		<< std::endl << "3) �� 500 �.�.  �� 1 ���.�.  +1%"
		<< std::endl << "4) ����� 1 ���.�. +1,5%" <<std::endl;
		
}

bool Depozit::CheckDepozit()
{
	if (database[userNumber].GetInfo()==0)
	return false;
	else return true;
}

void Depozit::OpenDepozit(int _timeperiodtype, int _sum,Date date)
{
	if (_timeperiodtype > 5 || _timeperiodtype < 1)
		throw DepozitExeption("�������� ������ �������");
	if (_sum > database[userNumber].GetAmount())
		throw DepozitExeption("������������ ������� �� �����");
	double perc = 0;
	switch (_timeperiodtype) {
	case 1: {
		perc = 5;
		break;
	}
	case 2: {
		perc = 5,5;
		break;
	}
	case 3: {
		perc = 6;
		break;
	}
	case 4: {
		perc = 6,5;
		break;
	}
	case 5: {
		perc = 7;
		break;
	}

	}
	if (_sum > 100 && _sum < 500)
		perc += 0.5;
	if (_sum >= 500 && _sum < 1000)
		perc += 1;
	if (_sum >= 1000)
		perc += 1.5;
	
	database[userNumber].depozitinfo.SetPecrcent(perc);
	database[userNumber].depozitinfo.SetSum(_sum);
	database[userNumber].depozitinfo.SetDate(date);
	database[userNumber].depozitinfo.CalcPercents();
}

void Depozit::DepozitInfo()
{
	std::cout << database[userNumber].GetInfo() <<std::endl;
}

void Depozit::GetPercents(int _n)
{
	database[userNumber].SetAmount(database[userNumber].depozitinfo.month[_n] + database[userNumber].GetAmount());
	database[userNumber].depozitinfo.month[_n] = 0;
}

void Depozit::CloseDepozit()
{
	for (size_t i = 0; i < database[userNumber].depozitinfo.month.GetCount(); i++)
	{
		database[userNumber].SetAmount(database[userNumber].depozitinfo.month[i] + database[userNumber].GetAmount());
		database[userNumber].depozitinfo.month[i] = 0;
	}
	database[userNumber].depozitinfo.SetSum(0);
	database[userNumber].depozitinfo.SetPecrcent(0);
	database[userNumber].depozitinfo.SetTimePeriod(0);
}

void Depozit::LogOut()
{
	ifauthorize = false;
	userNumber = -1;
}

std::istream & operator>>(std::istream & stream, Depozit & _f)
{
	
	int tmpcount;

	stream >>  tmpcount;
	for (int i = 0; i < tmpcount; i++) {
		ProcCenter tmp;
		stream >> tmp;
		_f.database.Add(tmp); 
	}
	return stream;
}

std::ostream & operator<<(std::ostream & stream, Depozit & _f)
{
	stream << _f.database.GetCount() <<std::endl;
	for (int i = 0; i < _f.database.GetCount();i++)
		stream << _f.database[i];
	return stream;
}
