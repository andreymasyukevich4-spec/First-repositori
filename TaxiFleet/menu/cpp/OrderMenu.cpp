#include "../header/OrderMenu.h"
#include "../../include/Order.h"
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
                
                int p;
                cout << "Enter Passengers: ";
                while (!(cin >> p) || p <= 0) {
                    clearInput();
                    cout << "Invalid number! Try again (>0): ";
                }
                clearInput();

                Order o(f, to, p);
                cout << "\nOrder created:\n";
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