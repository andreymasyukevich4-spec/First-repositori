#include "../header/MainMenu.h"
#include "../header/TaxiFleetMenu.h"
#include <iostream>
#include <limits>

using namespace std;

void showMainMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n!MAIN MENU!\n";
        cout << "1. Open TaxiFleet menu\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                showTaxiFleetMenu(fleet);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
}