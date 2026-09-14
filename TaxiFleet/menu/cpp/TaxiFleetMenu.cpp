#include "../Header/TaxiFleetMenu.h"
#include "../Header/CarMenu.h"
#include "../Header/OrderMenu.h"
#include <iostream>

using namespace std;

void showTaxiFleetMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n=== TAXIFLEET MENU ===\n";
        cout << "1. Show all cars\n";
        cout << "2. Show all orders\n";
        cout << "3. Add car\n";
        cout << "4. Add order\n";
        cout << "5. Assign order to car\n";
        cout << "6. Change car characteristics\n";
        cout << "7. Open Car menu\n";
        cout << "8. Open Order menu\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fleet.printAllCars();
                break;
            case 2:
                fleet.printAllOrders();
                break;
            case 3: {
                string r, m, t, d; int y, s;
                cout << "Enter Reg, Model, Year, Seats, Type, Driver: ";
                cin >> r >> m >> y >> s >> t >> d;
                fleet.addCar(Car(r, m, y, s, t, d));
                cout << "Car added!\n";
                break;
            }
            case 4: {
                string f, to; int p;
                cout << "Enter From, To, Passengers: ";
                cin >> f >> to >> p;
                fleet.addOrder(Order(f, to, p));
                cout << "Order added!\n";
                break;
            }
            case 5: {
                int idx;
                cout << "Enter order index to assign: ";
                cin >> idx;
                fleet.assignOrder(idx);
                break;
            }
            case 6: {
                int idx;
                cout << "Enter car index to change: ";
                cin >> idx;
                if (idx >= 0 && idx < (int)fleet.getCars().size()) {
                    int subChoice;
                    cout << "What to change?\n";
                    cout << "1. Seats\n2. Model\n3. Driver Name\nChoice: ";
                    cin >> subChoice;
                    if (subChoice == 1) {
                        int newSeats;
                        cout << "New seats: ";
                        cin >> newSeats;
                        fleet.getCars()[idx].setSeats(newSeats);
                        cout << "Updated!\n";
                    } else if (subChoice == 2) {
                        string newModel;
                        cout << "New model: ";
                        cin >> newModel;
                        fleet.getCars()[idx].setModel(newModel);
                        cout << "Updated!\n";
                    } else if (subChoice == 3) {
                        string newDriver;
                        cout << "New driver: ";
                        cin >> newDriver;
                        fleet.getCars()[idx].setDriverName(newDriver);
                        cout << "Updated!\n";
                    }
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            }
            case 7:
                showCarMenu();
                break;
            case 8:
                showOrderMenu();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}