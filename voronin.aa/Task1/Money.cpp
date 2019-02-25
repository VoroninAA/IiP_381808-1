#include "Money.h"
Money::Money() {
	c = 0;
	r = 0;
	z = '+';

}
Money::Money(char a, int b,int  d) {
	z = a;
	r = b;
    c = d;
}
Money::Money(const Money & _a) {
	c = _a.c;
	r = _a.r;
	z = _a.z;
}
Money::~Money() {
	c = 0;
	r = 0;
	z = '+';
	
}
Money& Money::operator=(const Money& m) {
	r = m.r;
	c = m.c;
	z = m.z;
	return *this;
}
bool Money::operator==(const Money& m) {
	if (r == m.r&&c == m.c&&z == m.z)
		return 1;
	else return 0;

}
ostream& operator<<(ostream& stream, const Money& m) {
	stream << m.z << m.r <<','   << m.c << endl;
	return stream;

}
istream& operator>>(istream& stream,Money& m) {
	char k;
	stream  >>m.z >> m.r >>k >> m.c ;
	return stream;

}
Money& Money::operator+(const Money& m) {
	double t1, t2,rez;
	t1 = r*100 + c ;
	t2 = m.r*100 + m.c ;
	if (z == '-') t1 = t1 * -1;
	if (m.z == '-') t2 = t2 * -1;
	rez=t2 + t1;

	r = (unsigned int)(rez/100);
	c =  (int)rez%100;
	if (rez < 0)
		z = '-';
		return *this;
	} //slozhenie s perevodom v deystvitelnoe chislo
Money& Money::operator-(const Money& m) {
	double t1, t2, rez;
	t1 = r * 100 + c;
	t2 = m.r * 100 + m.c;
	if (z == '-') t1 = t1 * -1;
	if (m.z == '-') t2 = t2 * -1;
	rez = t2 - t1;
	
	if (rez < 0)
		r = ((int)rez / 100)*-1;
	else r = ((int)rez / 100);
	if (rez<0)
		c = ((int)rez % 100)*-1;
	else c = ((int)rez % 100);
	if (rez > 0)
		z = '-';
		return *this;
	}//vichitanie s perevodom v deystvitelnoe chislo
Money operator*(const Money& m, double d) {
		 Money res;
		 double t1;
		 t1 = m.r * 100 + m.c;
		 if (m.z == '-') t1 = t1 * -1;
		 t1 = d * t1;
	
		 if (t1 < 0)
			 res.r = ((int)t1 / 100)*-1;
		 else res.r = ((int)t1 / 100);
		 if (t1 < 0)
			 res.c = ((int)t1 % 100)*-1;
		 else res.c = ((int)t1 % 100);
		 if (t1 < 0)
			 res.z = '-';
		 return res;

	 }//ymnozhenie s perevodom v deystvitelnoe chislo
Money operator/(const Money& m, double d) {

	 Money res;
	 double t1;
	 t1 = m.r * 100 + m.c;
	 if (m.z == '-') t1 = t1 * -1;
	 t1 = t1 / d;
	

	 if (t1 < 0)
		 res.r = ((int)t1 / 100)*-1;
	 else res.r = ((int)t1 / 100);
	 if (t1 < 0)
		 res.c = ((int)t1 % 100)*-1;
	 else res.c = ((int)t1 % 100);
	 if (t1 < 0)
		res.z  = '-';
	 return res;

 } //delenie s perevodom v deystvitelnoe chislo