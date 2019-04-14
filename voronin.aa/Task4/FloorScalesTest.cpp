#include"FloorScales.h"
#include<iostream>
#include<locale>
using namespace std;
//------------------------------
//В качестве тестирующей функции использовано двухэтапное меню
//Первое меню позволяет добавить пользователя, выбрать пользователя, 
//сохранить историю в файл, считать историю из файла и завершить программу
//Второе мненю открывается при выборе пользователя, чтобы продолжить работу с ним.
//В нем доступны методы работы с показаниями.
//------------------------------
int main() {
	setlocale(LC_CTYPE, "russian");
	int menu=-1;
	FloorScales test;
	ifstream fi;
	
	fi.open("test.txt");
	while (menu != 0) {
		cout << "Выберите действие" << endl << "0-Выход" << endl << "1-Добавить пользователя" << endl << "2-Выбрать пользователя" << endl <<"3-Записать историю в файл" << endl <<"4-Открыть историю из файла" << endl;
		cin >> menu;
		switch (menu) {
		case 0: break;
		case 1: {
			cout << "Введите имя пользователя" << endl;
			string username;
			cin >> username;
			test.AddUser(username);
			system("cls");
			break;

		}
		case 2:
		{			if (test.getAmount() == 0) {
			cout << "Список пуст!";
						break;
		}
		for (int i = 0; i < test.getAmount(); i++)
			cout << i << ". " << test.getName(i) << endl;
		int x;
		cin >> x;
		test.SetUser(x);
		int number=0 ;
		

		while (number != 9) {
			system("cls");
			cout << "Выберите действие" << endl << "0-Добавить показание" << endl << "1-Узнать начальную дату" << endl << "2-Узнать вес по дню" << endl
				<< "3-Узнать средний вес в месяце" << endl << "4-Узнать средний вес за все время" << endl << "5-Узнать минимальный вес в месяце" << endl
				<< "6-Узнать минимальный вес за все время" << endl << "7-Узнать максимальный вес в месяце" << endl << "8-Узнать максимальный вес за  все время" << endl
				<< "9-Выход" << endl;
			cin >> number;
			switch (number)
			{
			case 0:
			{
				cout << "Введите дату и вес" << endl;
				int w;
				int d, m, y;
				cin >> d >> m >> y >> w;
				test.Add(d, m, y, w);
				system("cls");
				break;
			}
			case 1:
			{
				Date datetest;
				datetest=test.GetFirstdate();
				Date wrong(-1,-1,-1);
				if (test.GetFirstdate() == wrong)
					cout << "Дата не найдена";
				else 
					cout<<datetest;
				system("pause");
				system("cls");
				break;
			}
			case 2: 
			{
				cout << "Введите дату" << endl;
				
				int d, m, y;
				cin >> d >> m >> y;
				if (test.GetWeight(d, m, y) == -1)
					cout << "Показание не найдено";
				else
					cout<<test.GetWeight(d, m, y);
				system("pause");
				system("cls");
				break;

			}
			case 3:
			{
				cout << "Введите дату" << endl;

				int d, m, y;
				cin >> d >> m >> y;
				if (test.FindMediumWeight(d, m, y) == 0)
					cout << "Показание не найдено";
				else
					cout << test.FindMediumWeight(d, m, y);
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				string testmed;
				if (test.FindMediumWeightAll(testmed) == 0)
					cout << "Показание не найдено";
				else
					cout << test.FindMediumWeightAll(testmed) <<' ' <<testmed;
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				cout << "Введите дату" << endl;

				int d, m, y;
				cin >> d >> m >> y;
				if (test.FindMinWeight(d, m, y) == 10000)
					cout << "Показание не нацдено";
				else
					cout << test.FindMinWeight(d, m, y);
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				string testmin;
				if (test.FindMinWeightAll(testmin) == 10000)
					cout << "Показание не найдено";
				else 
					cout << test.FindMinWeightAll(testmin)<<' '<<testmin;
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				cout << "Введите дату" << endl;

				int d, m, y;
				cin >> d >> m >> y;
				if (test.FindMaxWeight(d, m, y) == -1)
					cout << "показание не найдено";
				else
					cout << test.FindMaxWeight(d, m, y);
				system("pause");
				system("cls");
				break;
			}
			case 8:
			{
				string testmax;
				if (test.FindMaxWeightAll(testmax) == -1)
					cout << "Показание не найдено";
				else
					cout << test.FindMaxWeightAll(testmax)<<' '<<testmax;
				system("pause");
				system("cls");
				break;
			}


			}
		}
		system("cls");

		}

		case 3: {
			ofstream fo;
			fo.open("test.txt");
			fo << test;
			fo.close();
			system("cls");
			break; }
		case 4: {
			ifstream fi;

			fi.open("test.txt");
			fi >> test;
			fi.close();
			system("cls");
			break;
		}
		}
		
	}
	return 0;
}