#include "product.h"

product::product()
{
	name = "NA";
	stock = 0;
	price = 0;
	type = "NA";
	weight = 0;
	ship = false;
	prod_time = time_point<system_clock>{};
	exp_time = time_point<system_clock>{};
}

product::product(string n, int q, double p, string t, double w)
{
	name = n;
	stock = q;
	price = p;
	type = t;
	weight = w;
	ship = can_ship();
	prod_time = system_clock::now();
	if (can_expire()) {
		exp_time = prod_time + days{ 30 };
	}
	else {
		exp_time = time_point<system_clock>::max(); 
	}
}

void product::set_name(string s)
{
	name = s;
}

string product::get_name()
{
	return name;
}

void product::set_stock(int q)
{
	stock = q;
}

int product::get_stock()
{
	return stock;
}

void product::set_price(double p)
{
	price = p;
}

double product::get_price()
{
	return price;
}

void product::set_type(string t)
{
	type = t;
}

string product::get_type()
{
	return type;
}

void product::set_weight(double w)
{
	weight = w;
}

double product::get_weight()
{
	return weight;
}

void product::set_shipping(bool s)
{
	ship = s;
}

bool product::get_shipping()
{
	return ship;
}

void product::set_prod_time(time_point<system_clock> p)
{
	prod_time = p;
}

time_point<system_clock> product::get_prod_time()
{
	return prod_time;
}

bool product::can_expire()
{
	if (type == "food" || type == "drink")
		return true;
	return false;
}

bool product::is_expired()
{
	exp_time = prod_time + days{ 30 };
	return system_clock::now() > exp_time;
}

bool product::can_ship()
{
	if (weight > 0)
		return true;
	return false;
}
