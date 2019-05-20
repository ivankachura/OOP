#include "stdafx.h"
#include "Avto.h"
/*bool skidka = false;
int schet = 0;*/
using namespace std;

fstream file("file.txt");
Avto::Avto()
{

	file >> name;
	file >> maxspeed;
	file >> year;
	file >> price;
	
	br = false;
}


Avto::~Avto()
{
}

bool Avto::find_name(string &str)
{
	Find f(name,str);
	if (f.find())return true;
	else
		return false;
}

bool Avto::find_year(string &str)
{
	Find f(to_string(year),str);
	
	if (f.find())return true;
	else
		return false;
}

bool Avto::find_maxspeed(string &str)
{
	Find f(to_string(maxspeed),str);

	if (f.find())return true;
	else
		return false;
}

void Avto::bron()
{
	if (br == false) {
		
		if (b.check_money(price)) {
			b.minus_money(price);
			cout << "�� ������������� ���� ���������� ��� ������" << b.get_balance() << endl;
			br = true;
		}
		else cout << "������������ �������" << endl;
		




	}
	else cout << "���� ���������� ��� ������������" << endl;
}

void Avto::del_bron()
{
	if (br == true) {
		br = false;
		b.plus_money(price);
		cout << "����� ��������" << endl;
		cout << "��� ������:" << b.get_balance() << endl;
	}
	else cout << "�� �� ����������� ���� ����������" << endl;
}

bool Avto::get_br()
{

	return br;
}

int Avto::get_s()
{
	return b.get_skidka();
}



/*int Avto::get_balance()
{
	return balance;
}
*/
/*void Avto::bron_skidka()
{
	if (br == false) {


		if (balance >= (price / 2)) {
			schet++;
			balance -= (price / 2);


			br = true;

			cout << "���������� ������������" << endl;
			cout << "��� ������:" << get_balance() << endl;

		}
		else cout << "������������ �������" << endl;




	}
	else cout << "���� ���������� ��� ������������" << endl;
}

*/


std::ostream& operator<<(std::ostream& out, const Avto& avto)
{
	out << "���������� ����� " << avto.name << " c ������������ ��������� " << avto.maxspeed << ", " << avto.year << "���� �������." << "����:" << avto.price << endl;

	return out;
}