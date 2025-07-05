#pragma once
#include <iostream>
#include "string"
#include "string.h"
#include "customer.h"
#include "cart.h"
#include <vector>
using namespace std;
//assume shipping is always 30
class checkout
{
public:
	void checkout_items(customer& cus, cart& c);
};

