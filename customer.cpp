#include "customer.h"

customer::customer()
{
	name = "NA";
	balance = 0;
}

customer::customer(string n, int b)
{
	name = n;
	balance = b;
}

void customer::set_name(string n)
{
	name = n;
}

string customer::get_name()
{
	return name;
}

void customer::set_balance(int b)
{
	balance = b;
}

int customer::get_balance()
{
	return balance;
}

bool customer::can_afford(int price)
{
	if (price > balance)
		return false;
	return true;
}

void customer::pay(int price)
{
	if (can_afford(price)) {
		balance = balance - price;
		cout << "Remaining balance   " << balance << endl;
	}
	else {
		cout << "Balance is too low. \n";
		return;
	}
}
