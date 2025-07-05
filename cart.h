#pragma once
#include <iostream>
#include <vector>
#include "string"
#include "string.h"
#include "product.h"
using namespace std;
struct CartItem {
    product* p;
    int quantity;

    double get_total_price() const {
        return p->get_price() * quantity;
    }
};
class cart
{
	vector<CartItem> order;
public:
	void add(product* p, int quantity);
	vector<CartItem> get_items();
	bool is_empty();
};

