#pragma once
#include <iostream>
#include <vector>
#include "string"
#include "string.h"
using namespace std;
class customer
{
	int balance;
	string name;
public:
	customer();
	customer(string n, int b);
	void set_name(string n);
	string get_name();
	void set_balance(int b);
	int get_balance();
	bool can_afford(int price);
	void pay(int price);
};

