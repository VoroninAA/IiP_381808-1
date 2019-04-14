#pragma once
#include"Date.h"
#include<string>
// Класс коллекция, для хранения истории пользователя
class Collection
{
private:

	std::string user;
	double weight;
	
public:
	Date date;
	Collection();
	Collection(std::string _user);
	Collection(const Collection& _c);
	~Collection();
	double GetWeight();
	std::string GetUser();
	void SetUser(std::string str);
	void SetWeight(double w);
	Collection& operator=(const Collection& _collection);
	// Перегрузка операторов ввода/вывода
	friend std::ostream& operator<<(std::ostream& stream, const Collection& _f);
	friend std::istream& operator>>(std::istream& stream, Collection& _f);
};

