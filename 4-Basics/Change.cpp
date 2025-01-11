#include <iostream>

using namespace std;

int main() {

    int amount_in_cents {0};

    cout << "Enter an amount in cents: ";
    cin >> amount_in_cents;

    cout << "\nYou can provide this change as follows:" << endl;
    cout << "dollars  : " << amount_in_cents / 100 << endl;
    amount_in_cents %= 100;
    cout << "quarters : " << amount_in_cents / 25 << endl;
    amount_in_cents %= 25;
    cout << "dimes    : " << amount_in_cents / 10 << endl;
    amount_in_cents %= 10;
    cout << "nickels  : " << amount_in_cents / 5 << endl;
    amount_in_cents %= 5;
    cout << "pennies  : " << amount_in_cents << endl;   

    return 0;       
}