#include "../header/TaxiFleetMenu.h"
#include "../../include/TaxiFleet.h"
#include "../../include/Car.h"
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
        cout << "Oshibka: pustaya stroka. Vvedite snova: ";
    }
}

static int readYear(const string& prompt) {
    int y;
    while (true) {
        cout << prompt;
        if (cin >> y && y >= 2000 && y <= 2026) {
            clearInput();
            return y;
        }
        cout << "Oshibka! Vvedite korrektniy god (2000-2026): ";
        clearInput();
    }
}

static int readPositiveInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            clearInput();
            return val;
        }
        cout << "Oshibka! Chislo dolzhno byt bolshe 0: ";
        clearInput();
    }
}

static int readIndex(const string& prompt, int maxSize) {
    int idx;
    while (true) {
        cout << prompt;
        if (cin >> idx && idx >= 0 && idx < maxSize) {
            clearInput();
            return idx;
        }
        cout << "Oshibka! Vvedite index ot 0 do " << maxSize - 1 << ": ";
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
            case 1:
                fleet.printAllCars();
                break;
            case 2:
                fleet.printAllOrders();
                break;
            case 3: {
                cout << "\n!Dobavlenie mashiny!\n";
                string r = readString("Enter Registration Number: ");
                string m = readString("Enter Model: ");
                int y = readYear("Enter Year (2000-2026): ");
                int s = readPositiveInt("Enter Seats: ");
                string t = readString("Enter Type: ");
                string d = readString("Enter Driver Name: ");
                fleet.addCar(Car(r, m, y, s, t, d));
                cout << "Mashina uspeshno dobavlena!\n";
                break;
            }
            case 4: {
                cout << "\n!Dobavlenie zakaza!\n";
                string f = readString("Enter From Address: ");
                string to = readString("Enter To Address: ");
                int p = readPositiveInt("Enter Number of Passengers: ");
                fleet.addOrder(Order(f, to, p));
                cout << "Zakaz uspeshno dobavlen!\n";
                break;
            }
            case 5: {
                if (fleet.getOrders().empty()) {
                    cout << "Net dostupnyh zakazov.\n";
                    break;
                }
                cout << "\n!Proverka zakaza dlya vseh mashin!\n";
                cout << "Dostupno zakazov: 0 do " << fleet.getOrders().size() - 1 << "\n";
                int idx = readIndex("Enter order index to check: ", fleet.getOrders().size());
                fleet.checkOrderForAllCars(idx);
                break;
            }
            case 6: {
                if (fleet.getOrders().empty()) {
                    cout << "Net dostupnyh zakazov.\n";
                    break;
                }
                cout << "\n!Naznachenie zakaza!\n";
                cout << "Dostupno zakazov: 0 do " << fleet.getOrders().size() - 1 << "\n";
                int idx = readIndex("Enter order index to assign: ", fleet.getOrders().size());
                fleet.assignOrder(idx);
                break;
            }
            case 7: {
                if (fleet.getCars().empty()) {
                    cout << "Net dostupnyh mashin.\n";
                    break;
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
                break;
            }
            case 8: {
                if (fleet.getOrders().empty()) {
                    cout << "Net dostupnyh zakazov.\n";
                    break;
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
                break;
            }
            case 0:
                cout << "Vozvrashchenie v Main Menu...\n";
                break;
            default:
                cout << "Neverniy vibor! Poprobuyte snova.\n";
        }
    } while (choice != 0);
}