#include "stdafx.h"
#include "Balanse.h"

Balanse b;
void Balanse::plus_skidka()
{
	schet++;
	if (schet == 5)skidka++;
	else if (schet == 7)skidka++;

}

Balanse::Balanse()
{
	money = 100000;
	skidka = 0;
	schet = 0;
}


Balanse::~Balanse()
{
}

void Balanse::minus_money(int a)
{
	if (skidka == 0) {
		money -= a;
		plus_skidka();
	}
	else if (skidka == 1) {
		money -= a / 2;
		plus_skidka();
	}
	else if (skidka > 1) {
		money -= a / 3;
			plus_skidka();
	}
}

void Balanse::plus_money(int a)
{
	money += a/3;
}

bool Balanse::check_money(int a)
{
	if (skidka == 0 && money >= a)return true;
	else if (skidka == 1 && money >= a / 2)return true;
	else if (skidka == 2 && money >= a / 3)return true;
	else
	return false;
}


int Balanse::get_balance()
{
	return money;
}

int& Balanse::get_skidka()
{
	return skidka;
}
