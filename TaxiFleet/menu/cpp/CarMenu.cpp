#include "../header/CarMenu.h"
#include "../../include/Car.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

static void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static string readString(const string& prompt) {
    string result;
    cout << prompt;
    while (true) {
        getline(cin, result);
        if (!result.empty()) return result;
    }
}

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
                c.print();
                break;
            }
            case 2: {
                cout << "\n!Creating custom car!\n";
                string r = readString("Enter Registration Number: ");
                string m = readString("Enter Model: ");
                
                int y;
                cout << "Enter Year: ";
                while (!(cin >> y) || y < 1900 || y > 2026) {
                    clearInput();
                    cout << "Invalid year! Try again (1900-2026): ";
                }
                clearInput();

                int s;
                cout << "Enter Seats: ";
                while (!(cin >> s) || s <= 0) {
                    clearInput();
                    cout << "Invalid seats! Try again (>0): ";
                }
                clearInput();

                string t = readString("Enter Type: ");
                string d = readString("Enter Driver Name: ");

                Car c(r, m, y, s, t, d);
                cout << "\nCar created:\n";
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