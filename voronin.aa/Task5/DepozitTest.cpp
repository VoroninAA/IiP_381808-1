#include"Depozit.h"
#include <fstream>
#include<iostream>
#include<locale>
	//------------------------------
	//В качестве тестирующей функции использовано  меню
	// позволяющще осуществить вход и выход работы с конкретным пользователем,
	// а также использовать методы класса депозит
	//------------------------------
using namespace std;
int main() {
	Depozit test;
	setlocale(LC_CTYPE, "russian");
	int menu = -1;
	bool tag=true;
	ifstream fi;

	fi.open("test.txt");
	fi >> test;
	
	while (menu != 0) {
		while (tag) {
			cout << "Введите номер пользователя  и пароль" << endl;
			int tmpID;
			string tmpPass;
			cin >> tmpID;
			cin >> tmpPass;
			try
			{
				test.LogIn(tmpID, tmpPass);
				tag = false;
			}
			catch (DepozitExeption d)
			{
				cout << d.reason << endl;
			}
		}
			cout << "Выберите действие:" << endl
				<< "0-Выход" << endl << "1-Выход пользователя" << endl << "2-Показать информацию о депозитах" << endl << "3-Проверить наличие депозита" << endl << "4-Открыть депозит"
				<< endl  << "5-Проверить состояние депозита" << endl  << "6-Получить проценты на счет" << endl << "7- Закрыть депозит" << endl;
			cin >> menu;
			switch (menu) {
			case 0: break;
			case 1: {
				test.LogOut();
				tag = true;
				break;

			}
			case 2:
			{		
				test.ShowInfo(); 
				break;
			}

			case 3: {
				if (test.CheckDepozit())
					cout << "Депозит открыт" << endl;
				else cout << "Депозит не открыт" << endl;
				break; }
			case 4: {
				cout << "Введите временной промежуток, сумму и дату" << endl;
				int tmptime, tmpsum, tmpday, tmpmonth, tmpyear;
				cin >> tmptime >> tmpsum >> tmpday >> tmpmonth >> tmpyear;
				Date tmp(tmpday, tmpmonth, tmpyear);
				try
				{
					test.OpenDepozit(tmptime, tmpsum, tmp);
				}
				catch (DepozitExeption d)
				{
					cout << d.reason << endl;
				}
				
				break;
			}
			case 5: {
				test.DepozitInfo();
				break;
			}
			case 6: {
				int tmpn;
				cout << "Введите номер месяца" << endl;
				cin >> tmpn;
				test.GetPercents(tmpn);
				break;
			}
			case 7: {
				test.CloseDepozit();
				break;
			}
			}

		}
		return 0;
	}
	