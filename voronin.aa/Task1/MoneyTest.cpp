#include <iostream>
#include "Money.h"
using namespace std;
//test
int main() {
	Money test1('+', 10,80);
	Money test2('+',10,50);
	test2 = test2 + test1;
	test1 = test1*5.5;
	cout <<test1 << endl << test2;
	system("pause");
	return 0;
}