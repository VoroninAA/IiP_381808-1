#include "Polinom.h"
#include<cmath>
#include<iostream>
#include<fstream>
#include <string>

Polinom::Polinom()
{
	deg = 0;
	value =  new double[deg + 1];
	for (int i = 0; i <deg+1; i++) {
		value[i] = 0;
	}
}
Polinom::Polinom(int n, double mas[]) {
	deg = n;
    value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = mas[i];
	}
}
Polinom::Polinom(const Polinom& p) {
	deg = p.deg;
	value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = p.value[i];
	}
}
Polinom::~Polinom()
{
	free(value);
	deg = 0;
}
void Polinom::setdeg(int n) {
	 deg = n;
}
void Polinom::setvalue(double mas[]) {
	value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {

		value[i] = mas[i];
	}
}
int Polinom::showdeg()

{
	int max=0;
	for (int i = 0; i<deg+1; i++) {
		if (value[i] != 0)
			max = i;
	}
	return max;
}
double Polinom::showvalue(int n){
	return value[n];
	}
double Polinom :: findfun(double x) {
	double y = 0;
	for (int i = 0; i < deg+1; i++) {
		y += value[i] * pow(x, i);
	}
	return y;
}
Polinom Polinom::derivative() { 
	Polinom res(deg-1,value);
	for (int i = 0; i < res.deg+1; i++)
		res.value[i] = value[i + 1] * (i + 1) ;
	return res;
} 
Polinom& Polinom::operator=(const Polinom& p) {
	deg = p.deg;
    value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = p.value[i];
	
	}
	return *this;
}
ostream & operator<<(ostream & stream, const Polinom & p)
{
	stream << "Степень_полинома- " << p.deg <<' ';;

	for (int i = p.deg; i >= 0; i--) {
		if(i!=0)
	stream << p.value[i] <<"x^" <<i <<'+' ;
		else stream << p.value[i];
	}
	return stream;
}
istream & operator>>(istream & stream, Polinom & p)
{
	int pos = 0;
	string str1, str2;
	stream >> str1 >> p.deg  >> str2;
	string s1;
	s1 = str2.substr(0,str2.find_first_of('x'));
		p.value[p.deg] = stoi(s1);
	for (int i = p.deg-1; i >= 0; i--) {
		int tmp1, tmp2;

		string tmpstring;
		tmp1=str2.find('+',pos);
		tmp2 = str2.find('x', tmp1);
		pos = tmp2;
		tmpstring = str2.substr(tmp1 + 1, tmp2 - tmp1);
		p.value[i] = stoi(tmpstring);
}
	return stream;
}
double& Polinom::operator[](int n) {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше 0");
	if (n > deg)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше степени полинома");
	return value[n];
}
const double& Polinom::operator[](int n) const {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше нуля");
	if (n > deg)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше степени полинома");
	return value[n];
}
