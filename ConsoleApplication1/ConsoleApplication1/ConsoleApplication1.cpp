// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Avto.h"
using namespace std;
void broni(Avto* p, int n);
void find(Avto* p, int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	n = 5;
	Avto* p = new Avto[n];
	//cout << skidka;
	cout << "Добро пожаловать в автосалон" << endl;
	int k;
	do{
		cout << "1-посмотреть автомобили" << endl;
		cout << "2-перейти к бронированию" << endl;
		cout << "3-поиск" << endl;
		cout << "4-активировать скидку" << endl;
		cout << "0-выход" << endl;
		cin >> k;
		system("cls");
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
		}
		case 4: {
			//schet++;
			//skidka = true;
			//cout << schet <<" "<< skidka << endl;
			
			if (schet > 5) {
				cout << "вы активировали скидку 50%" << endl;
				skidka = true;
			}
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
		cin >> k;
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
			cin >> z;
			system("cls");
			if (!skidka)
				p[z - 1].bron();
			else p[z - 1].bron_skidka();

		}break;
		case 2: {
			for (int i = 0; i < n; i++)
			{
				cout << p[i] << endl;
			}
			cout << "введите номер ввтомобиля" << endl;
			int z;
			cin >> z;
			system("cls");
			p[z-1].del_bron();
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
		cin >> k;
		system("cls");
		switch (k)
		{
		case 1: {
			string na;
			cin >> na;
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_name(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль" << endl;
						int q;
						cin >> q;
						if (q == 1)if (!skidka)
							p[i ].bron();
						else p[i ].bron_skidka();;
					}
					else {
						cout << "не хотите ли отменить бронь" << endl;
						int q;
						cin >> q;
						if (q == 1)p[i].del_bron();
					}

				}

			}
		}break;
		case 2: {
			int na;
			cin >> na;
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_year(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль" << endl;
						int q;
						cin >> q;
						if (q == 1)if (!skidka)
							p[i ].bron();
						else p[i ].bron_skidka();;
					}
					else {
						cout << "не хотите ли отменить бронь" << endl;
						int q;
						cin >> q;
						if (q == 1)p[i].del_bron();
					}
				}
			}
				}break;
		case 3: {
			int na;
			cin >> na;
			system("cls");
			for (int i = 0; i < n; i++)
			{
				if (p[i].find_maxspeed(na)) {
					cout << p[i] << endl;
					if (!p[i].get_br()) {
						cout << "не хотите ли забронировать этот автомобиль" << endl;
						int q;
						cin >> q;
						if (q == 1)if (!skidka)
							p[i ].bron();
						else p[i ].bron_skidka();;
					}
					else {
						cout << "не хотите ли отменить бронь" << endl;
						int q;
						cin >> q;
						if (q == 1)p[i].del_bron();
					}
				}
			}
				}break;
			
		default:
			break;
			}
		} while (k != 0);
			
}
