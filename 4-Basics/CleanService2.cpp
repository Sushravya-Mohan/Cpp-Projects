#include <iostream>

using namespace std;

int main() {
    cout << "Hello, welcome to Frank's Cleaning Service" << endl;

    cout << "\nHow many small rooms would you like cleaned? ";
    int small_rooms {0};
    cin >> small_rooms;

    cout << "How many large rooms would you like cleaned? ";
    int large_rooms {0};
    cin >> large_rooms;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;

    const double small_room_price {25};
    cout << "Price per small room: $" << small_room_price << endl;
    double total_small_room_price {small_rooms * small_room_price};

    const double large_room_price {35};
    cout << "Price per large room: $" << large_room_price << endl;
    double total_large_room_price {large_rooms * large_room_price};

    double total_cost {total_small_room_price + total_large_room_price};
    cout << "Cost: $" << total_cost << endl;

    const double service_tax {0.06};
    cout << "Tax: $" << service_tax * total_cost << endl;

    cout << "===========================================" << endl;
    cout << "Total estimate: $" << (total_cost * service_tax) + total_cost << endl;

    const int  estimate_validity {30};  // days
    cout << "This estimate is valid for " << estimate_validity << "days." << endl;

    cout << endl;
    return 0;
}