// ConsoleApplication62.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "Avto.h"
#include "Find.h"
using namespace std;
void broni(Avto* p, int n);
void find(Avto* p, int n);
int durak();

int main()
{
	
	setlocale(LC_ALL, "Russian");
	int n;
	n = 5;
	Avto* p = new Avto[n];
	//cout << skidka;
	cout << "����� ���������� � ���������" << endl;
	string z;
	int k=-5;
		do {
		cout << "1-���������� ����������" << endl;
		cout << "2-������� � ������������" << endl;
		cout << "3-�����" << endl;
		cout << "4-������������ ������" << endl;
		cout << "0-�����" << endl;
		k = durak();
		system("cls");

		/*do {
			getline(cin, z);
			if (z.size() == 2 && z[0] <= 48 && z[0]>=57)k = atoi(z.c_str());
			cin.clear();
		} while (k == -1);*/
		switch (k)
		{
		case 1: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			break;
		}
		case 2: {
			broni(p, n);
		}
				break;
		case 3: {
			find(p, n);
		} break;
		case 4: {
			//schet++;
			//skidka = true;
			//cout << schet <<" "<< skidka << endl;

			if (p[1].get_s()==1)cout << "�� ������������ ������ 50%" << endl;
			else if(p[1].get_s() == 2)cout << "�� ������������ ������ 66%" << endl;
				
			else cout << "������������ ������������" << endl;
		}break;
		default:
			break;
		}

	} while (k != 0);

	return 0;
}

void broni(Avto* p, int n)
{
	int k;
	do {
		cout << "1-������������" << endl;
		cout << "2-�������� ������������" << endl;
		cout << "3-�������� �������������� ����������" << endl;
		cout << "0-�����" << endl;
		 k= durak();
		system("cls");
		switch (k)
		{
		case 1: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			cout << "������� ����� ����������" << endl;
			int z;
			 z = durak();

			system("cls");
			
				if(z>0 && z<n)p[z - 1].bron();
				else cout << "�������� ����� ����������" << endl;
			
		}break;
		case 2: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			cout << "������� ����� ����������" << endl;
			int z;
			z = durak();
			system("cls");

			if (z>0 && z<n)p[z - 1].del_bron();
			else cout << "�������� ����� ����������" << endl;
		}break;
		case 3: {
			int k = 0;
			for (int i = 0; i < n; i++)
			{

				if (p[i].get_br()) {
					cout << p[i] << endl;
					k++;
				}

			}
			if (k == 0)cout << "��� ��������������� �����������" << endl;
		}break;
		default:
			break;
		}
	} while (k != 0);
}

void find(Avto* p, int n)
{
	int k;
	do {
		cout << "1-����� �� �����" << endl;
		cout << "2-����� �� ���� ������� " << endl;
		cout << "3-����� �� ������������ ��������" << endl;
		cout << "0-�����" << endl;
		k = durak();
		system("cls");
		switch (k)
		{
		case 1: {
			string na;
			cout << "������� ��������, ������� ������ �����?" << endl;
			cin >> na;
			int u = 0;

			for (int i = 0; i < n; i++)
			{
				if (p[i].find_name(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "�� ������ �� ������������� ���� ����������(1-����, 0-�� ����)" << endl;
						int q;
						u++;
						
						 q=durak();
						
							if (q == 1)p[i].bron();
						
					}
					else {
						cout << "�� ������ �� �������� �����(1-����, 0-�� ����)" << endl;
						int q;
						q = durak();

						u++;
						if (q == 1)p[i].del_bron();
					}

				}

			}
			if (u==0)cout << "�� �������" << endl;
		}break;
		case 2: {
			string na;
			int u = 0;
			cout << "������� ���, ������� ������ �����?" << endl;
			cin >> na;
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_year(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "�� ������ �� ������������� ���� ����������(1-����, 0-�� ����)" << endl;
						int q;
						u++;
						q = durak();
						
						if (q == 1)p[i].bron();
						
					}
					else {
						cout << "�� ������ �� �������� �����(1-����, 0-�� ����)" << endl;
						int q;
						u++;
						q = durak();
						if (q == 1)p[i].del_bron();
					}
				}
			}
			if (u == 0)cout << "�� �������" << endl;
		}break;
		case 3: {
			string na;
			cout << "������� ��������, ������� ������ �����?" << endl;
			cin >> na;
			int u = 0;
		
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_maxspeed(na)) {
					cout << p[i] << endl;
					i++;
					if (!p[i].get_br()) {
						cout << "�� ������ �� ������������� ���� ���������� (1-����, 0-�� ����)" << endl;
						int q;
						u++;
						q = durak();
						
						if (q == 1)p[i].bron();
						
					}
					else {
						cout << "�� ������ �� �������� �����(1-����, 0-�� ����)" << endl;
						int q;
						u++;
						q = durak();
						if (q == 1)p[i].del_bron();
					}
				}
			}
			if (u == 0)cout << "�� �������" << endl;
		}break;

		default:
			break;
		}
	} while (k != 0);

}


int durak()
{
	int k = -1;
	do {

		string z;
		getline(cin, z);
		cin.clear();
		if (z.size() == 1 && z[0] >= '0' && z[0] <= '9')k = stoi(z);
		else cout << "������� �����" << endl;

	} while (k == -1);
	return k;
}
