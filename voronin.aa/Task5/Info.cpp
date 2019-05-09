#include "Info.h"



Info::Info()
{
	percent = 0;
	sum = 0;
	timeperiod = 0;
}

Info::Info(const Info & _i)
{
	percent = _i.percent;
	sum = _i.sum;
	startdate = _i.startdate;
	timeperiod = _i.timeperiod;
	for (int i = 0; i < month.GetCount(); i++)
	{
		month.Add(_i.month[i]);
	}
}


Info::~Info()
{
	percent = 0;
	sum = 0;
	timeperiod = 0;
}

void Info::CalcPercents()
{
	double tmp;
	tmp = sum * percent / 100;
	switch (timeperiod) {
	case 1:
	{
		for (size_t i = 0; i < 3; i++)
		{
			month.Add(tmp);
		}
		break;

	}
	case 2:
	{
		for (size_t i = 0; i <6; i++)
		{
			month.Add(tmp);
		}
		break;

	}
	case 3:
	{
		for (size_t i = 0; i < 12; i++)
		{
			month.Add(tmp);
		}
		break;

	}
	case 4:
	{
		for (size_t i = 0; i < 24; i++)
		{
			month.Add(tmp);
		}
		break;

	}
	case 5:
	{
		for (size_t i = 0; i < 36; i++)
		{
			month.Add(tmp);
		}
		break;

	}

	}
	
}

std::istream & operator>>(std::istream & stream, Info & _f)
{
	stream >> _f.percent >> _f.sum >> _f.startdate;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, Info & _f)
{
	stream << _f.percent << ' ' << _f.sum << ' ' << _f.startdate << std::endl;
	return stream;
}
