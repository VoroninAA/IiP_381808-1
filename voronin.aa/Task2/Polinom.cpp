#include "Polinom.h"
#include<cmath>
#include<iostream>
#include<fstream>


Polinom::Polinom()
{
	deg = 0;
	for (int i = 0; i < 13; i++) {
		value[i] = 0;
	}
}
Polinom::Polinom(int n) {
	deg = n;
}
Polinom::Polinom(int n, int mas[]) {
	deg = n;
	for (int i = 0; i < 13; i++) {
		value[i] = mas[i];
	}
}
Polinom::Polinom(const Polinom& p) {
	deg = p.deg;
	for (int i = 0; i < 12; i++) {
		value[i] = p.value[i];
	}
}
Polinom::~Polinom()
{
	deg = 0;
	for (int i = 0; i < 13; i++) {
		value[i] = 0;
	}
}
void Polinom::setdeg(int n) {
	if (n < 0) 
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше нуля");
		if (n > 12)
			throw PolExeption(IndexOutOfRange, "Значение не может быть больше 12");
		else deg = n;
	
}
void Polinom::setvalue(int mas[]) {
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
int Polinom::showvalue(int n){
	return value[n];
	}
int Polinom :: findfun(int x) {
	int y = 0;
	for (int i = 0; i < deg+1; i++) {
		y += value[i] * pow(x, i);
	}
	return y;
}
Polinom Polinom::derivative() { 
	Polinom res;
	res.deg = deg - 1;
	for (int i = 0; i < res.deg+1; i++)
		res.value[i] = value[i + 1] * (i + 1) ;
	return res;
} 
Polinom& Polinom::operator=(const Polinom& p) {
	deg = p.deg;
	for (int i = 0; i < deg+1; i++) {
		value[i] = p.value[i];
	
	}
	return *this;
}
ostream & operator<<(ostream & stream, const Polinom & p)
{
	for (int i = p.deg; i >= 0; i--) {
		if(i!=0)
	stream << p.value[i] <<"x^" <<i <<'+' ;
		else stream << p.value[i];
	}
	return stream;
}
istream & operator>>(istream & stream, Polinom & p)
{
	for (int i = p.deg; i >= 0; i--) {
		stream >> p.value[i];
}
	return stream;
}
int& Polinom::operator[](int n) {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше нуля");
	if (n > 12)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше 12");
	return value[n];
}
const int& Polinom::operator[](int n) const {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше нуля");
	if (n > 12)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше 12");
	return value[n];
}
