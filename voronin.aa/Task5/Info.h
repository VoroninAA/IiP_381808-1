#pragma once
#include "MyVector.h"
#include "Date.h"

class Info
// Вспомогательный класс информация о депозите. 
// Создан для поддержки класса ProcCenter
{
private:
	double percent;
	double sum;
	int timeperiod;
	
	Date startdate;

public:
	MyVector<double> month;
	Info();
	Info(const Info& _i);
	
	~Info();
	 double GetPercent() {return percent; }
	 double GetStartSum() { return sum; };
	 int GetTimePeriod() { return timeperiod; };
	 Date GetStartDate() { return startdate; };
	 void SetPecrcent(double _p) { percent = _p; }
	 void SetSum(double _s) { sum = _s; }
	 void SetTimePeriod(int _t) { timeperiod = _t; }
	 void SetDate(Date _d) { startdate= _d; }
	 void CalcPercents();
	 friend std::istream& operator>>(std::istream& stream, Info& _f);
	 friend std::ostream& operator<<(std::ostream& stream, Info& _f);
	 
};

