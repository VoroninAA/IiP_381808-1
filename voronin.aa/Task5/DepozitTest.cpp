#include"Depozit.h"
#include <fstream>
#include<iostream>
#include<locale>
	//------------------------------
	//� �������� ����������� ������� ������������  ����
	// ����������� ����������� ���� � ����� ������ � ���������� �������������,
	// � ����� ������������ ������ ������ �������
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
			cout << "������� ����� ������������  � ������" << endl;
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
			cout << "�������� ��������:" << endl
				<< "0-�����" << endl << "1-����� ������������" << endl << "2-�������� ���������� � ���������" << endl << "3-��������� ������� ��������" << endl << "4-������� �������"
				<< endl  << "5-��������� ��������� ��������" << endl  << "6-�������� �������� �� ����" << endl << "7- ������� �������" << endl;
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
					cout << "������� ������" << endl;
				else cout << "������� �� ������" << endl;
				break; }
			case 4: {
				cout << "������� ��������� ����������, ����� � ����" << endl;
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
				cout << "������� ����� ������" << endl;
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
	