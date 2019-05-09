#pragma once
#include"FIO.h"
#include "Info.h"
#include<fstream>
// ����� �������������� �����
// ������ ��� ��������� ������ ������ �������
// ������������ ������ � ���������� �������������
class ProcCenter
{
private:
    //--------------------------------------------
	// ���� ������
	int bankID; // ����� ����������� �����
	int amount; // ����� �� �����
	
	std::string password; // ������ ������������
	FIO fio; // ���
	//--------------------------------------------


public:
	Info depozitinfo; // ���������� � ��������

	// ������������ � ����������
	ProcCenter();// �� ���������
	ProcCenter(const ProcCenter& _pc);// ����������� �����������
	~ProcCenter();//����������
	 
	// ������ ��������� ����� ������
	int GetID() { return bankID; };
	int GetAmount() { return amount; };
	std::string GetPassword() { return password; };
	// ������ ��������� ����� ������
	
	void SetAmount(int _am) { amount = _am; }
	double GetInfo() { return depozitinfo.GetPercent(); }
	// ���������� ���������� �����/������
	friend std::ostream& operator<<(std::ostream& stream,  ProcCenter& _f);
	friend std::istream& operator>>(std::istream& stream, ProcCenter& _f);

};

