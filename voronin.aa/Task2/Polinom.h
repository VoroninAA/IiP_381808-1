#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Polinom
{
private:
	// Перегрузка операторов ввода/вывода
	friend ostream& operator<<(ostream& stream, const Polinom& p);
	friend istream& operator>>(istream& stream, Polinom& p);
	// Поля класса
	int deg; // Степень полинома
	double* value; // Хранение коэффициентов полинома

public:
	// Конструкторы и деструктор
	Polinom(); // Инициализатор по умолчанию
	Polinom(int deg, double value[]); // Инициализатор
	Polinom(const Polinom& p); // Копирование
	~Polinom(); // Деструктор

	// Методы класса
    void setdeg(int n); // Установить степень полинома
	void setvalue(double mas[]); // Установаить коэффициенты мономов полинома
	int showdeg(); // Показать максимальную степень полинома
	double showvalue(int n); //Показать коэффициент выбранной степени
	double findfun(double x); // Найти значение полинома в точке
	Polinom derivative(); // Найти производную полинома

	// Перегрузка операторов
	Polinom & operator=(const Polinom & p);
	double& Polinom::operator[](int n);
	const double& Polinom::operator[](int n) const;
	
};
enum PolEx
{
	IndexOutOfRange
};
// Описание исключений
struct PolExeption {
	PolEx type;
	string reason;
	PolExeption(PolEx t, string r) :
		type(t), reason(r)
	{}
};