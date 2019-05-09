#pragma once
#include"ProcCenter.h"
#include"MyVector.h"
#include"Date.h"
// Класс депозит
class Depozit
{
private:
	MyVector<ProcCenter> database; //База данных пользователя
	bool ifauthorize; // Авторизирован ли пользователь
	int userNumber;

public:
	Depozit(); //Конструктор по умолчанию
	~Depozit();//Деструктор
	Depozit(const Depozit& _d);// Конструктор копирования
	void LogIn(int _IDNumber, std::string _password);// Авторизовать пользователя
	void ShowInfo();// Показать информацию о возможных депозитах
	bool CheckDepozit();// Проверить наличие депозита
	void OpenDepozit(int _timeperiod, int _sum,Date date);// Открыть депозит
	void DepozitInfo();// Информация о депозите
	void GetPercents(int n);// Снять проценты депозита на счет по выбранному номеру месяца
	void CloseDepozit();// Закрыть депозит
	void LogOut();//Выход 


	friend std::istream& operator>>(std::istream& stream, Depozit& _f);
	friend std::ostream& operator<<(std::ostream& stream, Depozit& _f);
};
 
// Описание исключений
struct DepozitExeption {
	std::string reason;
	DepozitExeption(std::string r) :
		reason(r)
	{}
};