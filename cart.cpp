#include "cart.h"

void cart::add(product* p, int quantity)
{
    if (quantity > p->get_stock()) {
        cout << "Item out of stock.\n";
        return;
    }
    if (p->is_expired()) {
        cout << "Item is expired. \n";
        return;
    }
    p->set_stock(p->get_stock() - quantity);
    CartItem item = { p,quantity };
    order.push_back(item);
}

vector<CartItem> cart::get_items()
{
    return order;
}

bool cart::is_empty()
{
    return order.empty();
}
