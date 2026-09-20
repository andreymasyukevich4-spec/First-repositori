#include "../header/TaxiFleetMenu.h"
#include "../../include/TaxiFleet.h"
#include "../../include/Car.h"
#include "../../include/Order.h"
#include "../../include/Utils.h"
#include <iostream>

using namespace std;

void addCarMenu(TaxiFleet& fleet) {
    cout << "\n!Dobavlenie mashiny!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string t = readString("Enter Type: ");
    string d = readString("Enter Driver Name: ");
    fleet.addCar(Car(r, m, y, s, t, d));
    cout << "Mashina uspeshno dobavlena!\n";
}

void addOrderMenu(TaxiFleet& fleet) {
    cout << "\n!Dobavlenie zakaza!\n";
    string f = readString("Enter From Address: ");
    string to = readString("Enter To Address: ");
    int p = readPositiveInt("Enter Number of Passengers: ");
    fleet.addOrder(Order(f, to, p));
    cout << "Zakaz uspeshno dobavlen!\n";
}

void checkOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "Net dostupnyh zakazov.\n";
        return;
    }
    cout << "\n!Proverka zakaza dlya vseh mashin!\n";
    cout << "Dostupno zakazov: 0 do " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index to check: ", fleet.getOrders().size());
    fleet.checkOrderForAllCars(idx);
}

void assignOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "Net dostupnyh zakazov.\n";
        return;
    }
    cout << "\n!Naznachenie zakaza!\n";
    cout << "Dostupno zakazov: 0 do " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index to assign: ", fleet.getOrders().size());
    fleet.assignOrder(idx);
}

void editCarMenu(TaxiFleet& fleet) {
    if (fleet.getCars().empty()) {
        cout << "Net dostupnyh mashin.\n";
        return;
    }
    cout << "\n!Izmenenie harakteristik mashiny!\n";
    cout << "Dostupno mashin: 0 do " << fleet.getCars().size() - 1 << "\n";
    int idx = readIndex("Enter car index: ", fleet.getCars().size());
    
    cout << "\nChto izmenit?\n";
    cout << "1. Seats\n";
    cout << "2. Model\n";
    cout << "3. Driver Name\n";
    cout << "Choice: ";
    int sub;
    if (cin >> sub) {
        clearInput();
        if (sub == 1) {
            int seats = readPositiveInt("Enter new number of seats: ");
            fleet.getCars()[idx].setSeats(seats);
            cout << "Seats obnovleny!\n";
        } else if (sub == 2) {
            string model = readString("Enter new model: ");
            fleet.getCars()[idx].setModel(model);
            cout << "Model obnovlena!\n";
        } else if (sub == 3) {
            string driver = readString("Enter new driver name: ");
            fleet.getCars()[idx].setDriverName(driver);
            cout << "Driver obnovlen!\n";
        } else {
            cout << "Neverniy vibor!\n";
        }
    } else {
        clearInput();
    }
}

void editOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "Net dostupnyh zakazov.\n";
        return;
    }
    cout << "\n!Izmenenie harakteristik zakaza!\n";
    cout << "Dostupno zakazov: 0 do " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index: ", fleet.getOrders().size());
    
    cout << "\nChto izmenit?\n";
    cout << "1. From Address\n";
    cout << "2. To Address\n";
    cout << "3. Passengers\n";
    cout << "Choice: ";
    int sub;
    if (cin >> sub) {
        clearInput();
        if (sub == 1) {
            string addr = readString("Enter new From Address: ");
            fleet.getOrders()[idx].setFromAddress(addr);
            cout << "From Address obnovlen!\n";
        } else if (sub == 2) {
            string addr = readString("Enter new To Address: ");
            fleet.getOrders()[idx].setToAddress(addr);
            cout << "To Address obnovlen!\n";
        } else if (sub == 3) {
            int p = readPositiveInt("Enter new number of passengers: ");
            fleet.getOrders()[idx].setPassengers(p);
            cout << "Passengers obnovleni!\n";
        } else {
            cout << "Neverniy vibor!\n";
        }
    } else {
        clearInput();
    }
}

void showTaxiFleetMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n!TAXIFLEET MENU!\n";
        cout << "1. Pokazat vse mashiny\n";
        cout << "2. Pokazat vse zakazy\n";
        cout << "3. Dobavit novuyu mashinu\n";
        cout << "4. Dobavit noviy zakaz\n";
        cout << "5. Proverit zakaz dlya vseh mashin\n";
        cout << "6. Naznachit zakaz na mashinu\n";
        cout << "7. Izmenit harakteristiki mashiny\n";
        cout << "8. Izmenit harakteristiki zakaza\n";
        cout << "0. Nazad v Main Menu\n";
        cout << "Choice: ";
        
        if (!(cin >> choice)) {
            cout << "Oshibka vvoda! Vvedite chislo.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: fleet.printAllCars(); break;
            case 2: fleet.printAllOrders(); break;
            case 3: addCarMenu(fleet); break;
            case 4: addOrderMenu(fleet); break;
            case 5: checkOrderMenu(fleet); break;
            case 6: assignOrderMenu(fleet); break;
            case 7: editCarMenu(fleet); break;
            case 8: editOrderMenu(fleet); break;
            case 0: cout << "Vozvrashchenie v Main Menu...\n"; break;
            default: cout << "Neverniy vibor! Poprobuyte snova.\n";
        }
    } while (choice != 0);
}