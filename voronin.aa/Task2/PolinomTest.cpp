#include "Polinom.h"
#include<fstream>
#include<iostream>
#include<string>
#include<locale>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "russian");
    // Тест инициализатора
	int mas[13];
	for (int i = 0; i < 13; i++)
		mas[i] = i;
	Polinom a(12, mas);
	cout << "Инициализация- " << a << endl;
	// Тест установки степени и значений
	Polinom b;
	try {
		b.setdeg(12);
	}
	catch (PolExeption& ex) {
		cout << ex.reason << endl;
	}
	b.setvalue(mas);

	// Тест вывода степени и значений
	int testdeg;
	int testvalue;
	testdeg = a.showdeg();
	testvalue = a.showvalue(5);
	cout << "Степень а = " <<testdeg << endl;
	cout << "Значение монома 5 степени = " << testvalue << endl;
	 
	// Тест нахождения функции
	int t = a.findfun(1);
	cout << "Значение функции= " << t << endl;
	// Тест производной
	Polinom c;
	c = a.derivative();
	cout << "Производная= " << c << endl;
	// Тест оператора присваивания
	Polinom f;
	f = a;
	cout << "Оператор = " << f << endl;

	// Тест вывода в файл
	ofstream fo;
	fo.open("test.txt");
	fo << c;
	fo.close();

	// Тест ввода из файла
	ifstream fi;
	fi.open("test1.txt");
		Polinom d(12);
		fi >> d;
		fi.close();

	system("pause");
	return 0;
	
}