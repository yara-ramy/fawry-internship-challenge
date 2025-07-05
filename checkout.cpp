#include "checkout.h"

void checkout::checkout_items(customer& cus, cart& c)
{
	if (c.is_empty()) {
		cout << "Cart is empty.\n";
		return;
	}
	double subtotal = 0.0;
	double totWeight = 0.0;
	double shippingFee = 0.0;
	vector<CartItem> item = c.get_items();
	for (const CartItem& items : item) {
		product* p = items.p;
		double tot = p->get_price() * items.quantity;
		subtotal = subtotal + tot;
		if (p->can_ship()) {
			double w = p->get_weight() * items.quantity;
			totWeight = totWeight + w;
		}
	}
	if (totWeight > 0) {
		shippingFee = 30;
	}
	double total = subtotal + shippingFee;
	if (!cus.can_afford(total)) {
		cout << "Insufficient customer balance\n";
		return;
	}
	cout << "** Shipment notice **\n";
	for (const CartItem& items : item) {
		product* p = items.p;
		if (p->can_ship()) {
			double w = p->get_weight() * items.quantity;
			totWeight =totWeight + w;
			cout << items.quantity << "x " << p->get_name() << endl;  
		}
	}
	cout << "Total package weight  " << totWeight <<"kg\n" << endl;
	cout << "** Checkout receipt **\n";
	for (const CartItem& items : item) {
		product* p = items.p;
		double tot = p->get_price() * items.quantity;
		cout << items.quantity << "x " << items.p->get_name() << "  " << tot << endl;
	}
	cout << "---------------------------\n";
	cout << "Subtotal   " << subtotal << endl;
	cout << "Shipping   " << shippingFee<< endl;
	cout << "Amount   " << total << endl;
	cus.pay(total);
}
