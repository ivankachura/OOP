#include "Avto.h"
bool skidka = false;
 int schet = 0;
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

bool Avto::find_name(string& str)
{
	if (name == str)return true;
	else
	return false;
}

bool Avto::find_year(int ye)
{
	if (year == ye)return true;
	else
		return false;
}

bool Avto::find_maxspeed(int sp)
{
	if (maxspeed == sp)return true;
	else
	return false;
}

void Avto::bron()
{
	if (br == false) {
		
		
			if (balance >= price) {
				schet++;
				balance -= price;

				
				br = true;
				
				cout << "���������� ������������" << endl;
				cout << "��� ������:"<<get_balance() << endl;

			}
		else cout << "������������ �������" << endl;
		
		
		
		
	}
	else cout << "���� ���������� ��� ������������" << endl;
}

void Avto::del_bron()
{
	if (br == true) {
		br = false;
		balance += (price / 2);
		cout << "����� ��������" << endl;
		cout << "��� ������:" << get_balance() << endl;
	}
	else cout << "�� �� ����������� ���� ����������" << endl;
}

bool Avto::get_br()
{

	return br;
}

int Avto::get_balance()
{
	return balance;
}

void Avto::bron_skidka()
{
	if (br == false) {


		if (balance >= (price/2)) {
			schet++;
			balance -= (price/2);


			br = true;

			cout << "���������� ������������" << endl;
			cout << "��� ������:" << get_balance() << endl;

		}
		else cout << "������������ �������" << endl;




	}
	else cout << "���� ���������� ��� ������������" << endl;
}




std::ostream& operator<<(std::ostream& out, const Avto& avto)
{
	out <<"���������� ����� " << avto.name << " c ������������ ��������� " << avto.maxspeed << ", " << avto.year << "���� �������." << "����:" << avto.price << endl;

	return out;
}

