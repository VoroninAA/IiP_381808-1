#pragma once
#include<fstream>
#include<string>
// ����� �������� ���
class FIO
{

private:
	std::string name;
	std::string surname;
	std::string patronymic;
public:
	FIO();
	~FIO();
	std::string GetName() { return name; };
	std::string GetSurname() { return surname; };
	std::string GetPatronymic() { return patronymic; };
	void SetName(std::string _n) { name = _n; };
	void SetSurname(std::string _sn) { surname = _sn; };
	void SetPatronymic(std::string _pat) { patronymic = _pat; };
	FIO& operator=(const FIO& _f);

	// ���������� ���������� �����/������
	
	friend std::ostream& operator<<(std::ostream& stream,const FIO& _f);
	friend std::istream& operator>>(std::istream& stream, FIO& _f);

};
