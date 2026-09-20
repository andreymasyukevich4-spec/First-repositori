#include "../header/OrderMenu.h"
#include "../../include/Order.h"
#include "../../include/Utils.h"
#include <iostream>

using namespace std;

void showOrderMenu() {
    int choice;
    do {
        cout << "\n!ORDER CONSTRUCTOR MENU!\n";
        cout << "1. Create order\n";
        cout << "0. Back\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: {
                cout << "\n!Creating order!\n";
                string f = readString("Enter From Address: ");
                string to = readString("Enter To Address: ");
                int p = readPositiveInt("Enter Passengers: ");
                Order o(f, to, p);
                cout << "\nOrder created:\n";
                cout << o;
                break;
            }
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}