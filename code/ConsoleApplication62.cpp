// ConsoleApplication62.cpp: определяет точку входа для консольного приложения.
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
	cout << "Добро пожаловать в автосалон" << endl;
	string z;
	int k=-5;
		do {
		cout << "1-посмотреть автомобили" << endl;
		cout << "2-перейти к бронированию" << endl;
		cout << "3-поиск" << endl;
		cout << "4-активировать скидку" << endl;
		cout << "0-выход" << endl;
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

			if (p[1].get_s()==1)cout << "вы активировали скидку 50%" << endl;
			else if(p[1].get_s() == 2)cout << "вы активировали скидку 66%" << endl;
				
			else cout << "недостаточно бронирований" << endl;
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
		cout << "1-бронирование" << endl;
		cout << "2-отменить бронирование" << endl;
		cout << "3-показать забронированые автомобили" << endl;
		cout << "0-назад" << endl;
		 k= durak();
		system("cls");
		switch (k)
		{
		case 1: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			cout << "введите номер ввтомобиля" << endl;
			int z;
			 z = durak();

			system("cls");
			
				if(z>0 && z<n)p[z - 1].bron();
				else cout << "неверный номер автомобиля" << endl;
			
		}break;
		case 2: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			cout << "введите номер ввтомобиля" << endl;
			int z;
			z = durak();
			system("cls");

			if (z>0 && z<n)p[z - 1].del_bron();
			else cout << "неверный номер автомобиля" << endl;
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
			if (k == 0)cout << "нет забронированных автомобилей" << endl;
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
		cout << "1-поиск по имени" << endl;
		cout << "2-поиск по году выпуска " << endl;
		cout << "3-поиск по максимальной скорости" << endl;
		cout << "0-назад" << endl;
		k = durak();
		system("cls");
		switch (k)
		{
		case 1: {
			string na;
			cout << "введите название, которое хотите найти?" << endl;
			cin >> na;
			int u = 0;

			for (int i = 0; i < n; i++)
			{
				if (p[i].find_name(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль(1-хочу, 0-не хочу)" << endl;
						int q;
						u++;
						
						 q=durak();
						
							if (q == 1)p[i].bron();
						
					}
					else {
						cout << "не хотите ли отменить бронь(1-хочу, 0-не хочу)" << endl;
						int q;
						q = durak();

						u++;
						if (q == 1)p[i].del_bron();
					}

				}

			}
			if (u==0)cout << "не найдено" << endl;
		}break;
		case 2: {
			string na;
			int u = 0;
			cout << "введите год, который хотите найти?" << endl;
			cin >> na;
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_year(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль(1-хочу, 0-не хочу)" << endl;
						int q;
						u++;
						q = durak();
						
						if (q == 1)p[i].bron();
						
					}
					else {
						cout << "не хотите ли отменить бронь(1-хочу, 0-не хочу)" << endl;
						int q;
						u++;
						q = durak();
						if (q == 1)p[i].del_bron();
					}
				}
			}
			if (u == 0)cout << "не найдено" << endl;
		}break;
		case 3: {
			string na;
			cout << "введите скорость, которую хотите найти?" << endl;
			cin >> na;
			int u = 0;
		
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_maxspeed(na)) {
					cout << p[i] << endl;
					i++;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль (1-хочу, 0-не хочу)" << endl;
						int q;
						u++;
						q = durak();
						
						if (q == 1)p[i].bron();
						
					}
					else {
						cout << "не хотите ли отменить бронь(1-хочу, 0-не хочу)" << endl;
						int q;
						u++;
						q = durak();
						if (q == 1)p[i].del_bron();
					}
				}
			}
			if (u == 0)cout << "не найдено" << endl;
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
		else cout << "введите цифру" << endl;

	} while (k == -1);
	return k;
}
