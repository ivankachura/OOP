#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
static int balance=10000;
 extern bool skidka;
   extern int schet;
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
	bool find_year(int ye);
	bool find_maxspeed(int sp);
	void bron();
	void del_bron();
	bool get_br();
	static int get_balance();
	void bron_skidka();
	
	
};

