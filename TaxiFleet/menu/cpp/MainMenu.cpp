#include "../Header/MainMenu.h"
#include "../Header/TaxiFleetMenu.h"
#include <iostream>

using namespace std;

void showMainMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. TaxiFleet\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showTaxiFleetMenu(fleet);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}