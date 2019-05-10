#pragma once
#include"FIO.h"
#include "Info.h"
#include<fstream>
// Класс процессинговый центр
// Создан для поддержки работы класса депозит
// Осуществляет работу с конкретным пользователем
class ProcCenter
{
private:
    //--------------------------------------------
	// Поля класса
	int bankID; // Номер зарплатного счета
	int amount; // Сумма на счету
	
	std::string password; // Пароль пользователя
	FIO fio; // ФИО
	//--------------------------------------------


public:
	Info depozitinfo; // Информация о депозите

	// Конструкторы и деструктор
	ProcCenter();// По умолчанию
	ProcCenter(const ProcCenter& _pc);// Конструктор копирования
	~ProcCenter();//Деструктор
	 
	// Методы получения полей класса
	int GetID() { return bankID; };
	int GetAmount() { return amount; };
	std::string GetPassword() { return password; };
	// Методы установки полей класса
	
	void SetAmount(int _am) { amount = _am; }
	double GetInfo() { return depozitinfo.GetPercent(); }
	// Перегрузка операторов ввода/вывода
	friend std::ostream& operator<<(std::ostream& stream,  ProcCenter& _f);
	friend std::istream& operator>>(std::istream& stream, ProcCenter& _f);

};

