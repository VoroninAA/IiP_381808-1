#pragma once
#include"ProcCenter.h"
#include"MyVector.h"
#include"Date.h"
// ����� �������
class Depozit
{
private:
	MyVector<ProcCenter> database; //���� ������ ������������
	bool ifauthorize; // ������������� �� ������������
	int userNumber;

public:
	Depozit(); //����������� �� ���������
	~Depozit();//����������
	Depozit(const Depozit& _d);// ����������� �����������
	void LogIn(int _IDNumber, std::string _password);// ������������ ������������
	void ShowInfo();// �������� ���������� � ��������� ���������
	bool CheckDepozit();// ��������� ������� ��������
	void OpenDepozit(int _timeperiod, int _sum,Date date);// ������� �������
	void DepozitInfo();// ���������� � ��������
	void GetPercents(int n);// ����� �������� �������� �� ���� �� ���������� ������ ������
	void CloseDepozit();// ������� �������
	void LogOut();//����� 


	friend std::istream& operator>>(std::istream& stream, Depozit& _f);
	friend std::ostream& operator<<(std::ostream& stream, Depozit& _f);
};
 
// �������� ����������
struct DepozitExeption {
	std::string reason;
	DepozitExeption(std::string r) :
		reason(r)
	{}
};