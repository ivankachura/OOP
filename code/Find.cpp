#include "stdafx.h"
#include "Find.h"
using namespace std;

Find::Find(string thing,string other)
{
	this->thing = thing;
	this->other = other;;
}


Find::~Find()
{
}

bool Find::find()
{
	if (thing == other)return true;
	 else return false;
}
