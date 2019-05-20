#pragma once

#include "stdafx.h"
#include <fstream>


#include "Find.h"
#include "Balanse.h"
using namespace std;
/*static int balance = 10000;
extern bool skidka;
extern int schet;*/
extern Balanse b;
class Avto
{
	
	string name;
	int price, maxspeed, year, skidka;
	bool br;
	

public:
	Avto();

	~Avto();
	friend std::ostream& operator<< (std::ostream& out, const Avto& avto);
	bool find_name(string &str);
	bool find_year(string &str);
	bool find_maxspeed(string &str);
	void bron();
	void del_bron();
	bool get_br();
	/*static int get_balance();
	void bron_skidka();*/
	static int get_s();


};



