#include "checkout.h"
#include <chrono>
#include <thread>
using namespace std;
int main() {
    product* cheese = new product("Cheese 200g", 5, 100.0, "food", 0.2);
    product* biscuits = new product("Biscuits 700g", 3, 150.0, "food", 0.7);
    product* tv = new product("TV", 2, 500.0, "electronics", 10.0);
    product* scratchCard = new product("Mobile Scratch Card", 10, 50.0, "digital", 0.0);
    product* gameKey = new product("Game Key", 5, 200.0, "digital", 0.0);
    product* expiredCheese = new product("Expired Cheese", 1, 100.0, "food", 0.2);
    auto old = system_clock::now() - hours(24 * 40); // Simulate expired production time (40 days ago)
    expiredCheese->set_prod_time(old);
    checkout ch;

    
    // TEST CASE 1: Valid mixed checkout
    /*
    customer cust1("Yara", 1000);
    cart c1;
    c1.add(cheese, 2);
    c1.add(biscuits, 1);
    c1.add(scratchCard, 1);
    ch.checkout_items(cust1, c1);
    
    */
    
    // TEST CASE 2: Expired product
    /*
    customer cust2("Ali", 500);
    cart c2;
    c2.add(expiredCheese, 1);
    ch.checkout_items(cust2, c2);
    
    */
   
    // TEST CASE 3: Quantity exceeds stock
    /*
    customer cust3("Mona", 1000);
    cart c3;
    c3.add(tv, 5); // TV stock is only 2
    ch.checkout_items(cust3, c3);
    */

   
    // TEST CASE 4: Insufficient balance
    /*
    customer cust4("Sara", 100);
    cart c4;
    c4.add(biscuits, 1);  // 150
    ch.checkout_items(cust4, c4);
    
    */
    
    // TEST CASE 5: Digital-only checkout
    /*
    customer cust5("Omar", 500);
    cart c5;
    c5.add(scratchCard, 3); // 3 x 50 = 150
    ch.checkout_items(cust5, c5);
    
    */
    
    // TEST CASE 6: Exact balance match
    /*
    customer cust6("Lina", 430);
    cart c6;
    c6.add(cheese, 2);    // 200
    c6.add(biscuits, 1);  // 150
    c6.add(scratchCard, 1); // 50  subtotal = 400
    ch.checkout_items(cust6, c6); // 400 + 30 shipping = 430
    
    */
    
    // TEST CASE 7: Zero weight product
    /*
    customer cust7("Kareem", 500);
    cart c7;
    c7.add(scratchCard, 2); // no shipping fee
    ch.checkout_items(cust7, c7);
    
    */
    
    // TEST CASE 8: Non-expiring, non-shippable
    /*
    customer cust8("Nour", 600);
    cart c8;
    c8.add(gameKey, 2); // no expiry, no shipping
    ch.checkout_items(cust8, c8);
    */
    delete cheese;
    delete biscuits;
    delete tv;
    delete scratchCard;
    delete gameKey;
    delete expiredCheese;
    return 0;
}