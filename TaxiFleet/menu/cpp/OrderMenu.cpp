#include "../Header/OrderMenu.h"
#include <iostream>

using namespace std;

void showOrderMenu() {
    int choice;
    do {
        cout << "\n=== ORDER MENU ===\n";
        cout << "1. Create order\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string f, to; int p;
                cout << "Enter From, To, Passengers: ";
                cin >> f >> to >> p;
                Order o(f, to, p);
                o.print();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}