#pragma once
#include"NotSTLVector.h"
#include<fstream>
#include"Collection.h"
// Класс весы напольные
class FloorScales
{
private:
	//Поля класса
	NotSTLVector<std::string> user; //Пользователи
	int amount; // Количество пользователей
	std::string currentuser; // Текущий пользователь
	NotSTLVector<Collection> collection; //Хранение наблюдений
	int size;//Размер коллекции

public:
	// Конструкторы и деструктор
	FloorScales();// По умолчанию
//	FloorScales(std::string str, int day, int month, int year, double weight); // Инициализатор
	FloorScales(const FloorScales& _f); // Конструктор конпирования
	~FloorScales(); // Деструктор

	// Методы класса для работы с пользователем
	void AddUser(std::string _user); // Добавить пользователя
	void SetUser(int _usernumber); // Установить текущего пользователя
	int getAmount() { return amount; } // Узнать количество пользователей
	std::string getName(int index) { return user[index]; } // Узнать имя пользователя по номеру

	// Методы класса для работы с коллекцией
	void Add( int _day, int _month, int _year, double _weight); // Добаваить показание
	Date GetFirstdate(); // Узнать начальную дату выбранного пользователя
	double GetWeight(int _day, int _month, int _year); // Узнать вес в выбранный день.
	double FindMediumWeight(int _day, int _month, int _year); // Узнать средний вес в выбранном месяце
	double FindMediumWeightAll(std::string& str); // Узнать средний вес за все время и дату пользования
	double FindMinWeight(int _day, int _month, int _year);  // Узнать минимальный вес в месяце
	double FindMinWeightAll(std::string& str);  // Узнать минимальный вес за все время и дату пользования
	double FindMaxWeight(int _day, int _month, int _year);// Узнать максимальный вес в месяце
	double FindMaxWeightAll(std::string& str);  // Узнать максимальный вес за все время и дату пользования

	// Перегрузка операторов ввода/вывода
	// При выводе сначала выводится количество пользователей, потом имена пользователей. Затем количество показаний и показания
	friend std::ostream& operator<<(std::ostream& stream, const FloorScales& _f);
	friend std::istream& operator>>(std::istream& stream, FloorScales& _f);
};

