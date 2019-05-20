#pragma once
#include "stdafx.h"
class Balanse
{
	int money;
	int skidka;
	int schet;
	void plus_skidka();
public:
	Balanse();
	~Balanse();
	void minus_money(int a);
	void plus_money(int a);
	bool check_money(int a);
	int get_balance();
	int& get_skidka();

};

