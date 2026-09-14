#include "../Header/CarMenu.h"
#include <iostream>

using namespace std;

void showCarMenu() {
    int choice;
    do {
        cout << "\n=== CAR MENU ===\n";
        cout << "1. Create default car\n";
        cout << "2. Create custom car\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Car c;
                c.print();
                break;
            }
            case 2: {
                string r, m, t, d; int y, s;
                cout << "Enter Reg, Model, Year, Seats, Type, Driver: ";
                cin >> r >> m >> y >> s >> t >> d;
                Car c(r, m, y, s, t, d);
                c.print();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}