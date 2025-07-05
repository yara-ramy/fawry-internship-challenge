#pragma once
#include <iostream>
#include "string"
#include "string.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
//assume shelf life is 30 days for all products that can expire
class product
{
	string name;
	int stock;
	double price;
	string type;
	double weight;
	bool ship;
	time_point<system_clock> prod_time;
	time_point<system_clock> exp_time;
public:
	product();
	product(string n, int q, double p, string t, double w);
	void set_name(string s);
	string get_name();
	void set_stock(int q);
	int get_stock();
	void set_price(double p);
	double get_price();
	void set_type(string t);
	string get_type();
	void set_weight(double w);
	double get_weight();
	void set_shipping(bool s);
	bool get_shipping();
	void set_prod_time(time_point<system_clock> p);
	time_point<system_clock> get_prod_time();
	
	bool can_expire(); //check type law food aw drink return true
	bool is_expired();
	bool can_ship();
};

