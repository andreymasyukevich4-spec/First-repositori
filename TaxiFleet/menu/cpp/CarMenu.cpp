#include "../header/CarMenu.h"
#include "../../include/Car.h"
#include "../../include/Utils.h"
#include <iostream>

using namespace std;

void showCarMenu() {
    int choice;
    do {
        cout << "\n!CAR CONSTRUCTOR MENU!\n";
        cout << "1. Create default car\n";
        cout << "2. Create custom car\n";
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
                Car c;
                cout << "\nDefault car created:\n";
                cout << c;
                break;
            }
            case 2: {
                cout << "\n!Creating custom car!\n";
                string r = readString("Enter Registration Number: ");
                string m = readString("Enter Model: ");
                int y = readYear("Enter Year: ");
                int s = readPositiveInt("Enter Seats: ");
                string t = readString("Enter Type: ");
                string d = readString("Enter Driver Name: ");
                Car c(r, m, y, s, t, d);
                cout << "\nCar created:\n";
                cout << c;
                break;
            }
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}