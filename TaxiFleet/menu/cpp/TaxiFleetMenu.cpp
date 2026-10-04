#include "../header/TaxiFleetMenu.h"
#include "../../include/TaxiFleet.h"
#include "../../include/Car.h"
#include "../../include/Sedan.h"
#include "../../include/Minivan.h"
#include "../../include/ElectricCar.h"
#include "../../include/Order.h"
#include "../../include/Utils.h"
#include <iostream>

using namespace std;

void addSedanMenu(TaxiFleet& fleet) {
    cout << "\n!Dobavlenie Sedan!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double fuel = readPositiveInt("Enter Fuel Consumption (l/100km): ");
    int hasSeat = readPositiveInt("Has child seat? (1-yes, 0-no): ");
    fleet += new Sedan(r, m, y, s, d, fuel, hasSeat == 1);
    cout << "Sedan uspeshno dobavlen!\n";
}

void addMinivanMenu(TaxiFleet& fleet) {
    cout << "\n!Dobavlenie Minivan!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double fuel = readPositiveInt("Enter Fuel Consumption (l/100km): ");
    int luggage = readPositiveInt("Enter Max Luggage (l): ");
    fleet += new Minivan(r, m, y, s, d, fuel, luggage);
    cout << "Minivan uspeshno dobavlen!\n";
}

void addElectricCarMenu(TaxiFleet& fleet) {
    cout << "\n!Dobavlenie ElectricCar!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double battery = readPositiveInt("Enter Battery Capacity (kWh): ");
    int charge = readPositiveInt("Enter Charge Level (%): ");
    fleet += new ElectricCar(r, m, y, s, d, battery, charge);
    cout << "ElectricCar uspeshno dobavlen!\n";
}

void addCarMenu(TaxiFleet& fleet) {
    cout << "\nKakuyu mashinu dobavit?\n";
    cout << "1. Sedan\n";
    cout << "2. Minivan\n";
    cout << "3. ElectricCar\n";
    cout << "0. Otmena\n";
    cout << "Choice: ";
    int choice;
    if (!(cin >> choice)) {
        clearInput();
        cout << "Oshibka vvoda!\n";
        return;
    }
    clearInput();

    switch (choice) {
        case 1: addSedanMenu(fleet); break;
        case 2: addMinivanMenu(fleet); break;
        case 3: addElectricCarMenu(fleet); break;
        case 0: cout << "Otmena.\n"; break;
        default: cout << "Neverniy vibor!\n";
    }
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

    Car* car = fleet.getCars()[idx];
    cout << "\nTekushaya mashina: " << car->getType() << "\n";

    cout << "\nChto izmenit?\n";
    cout << "1. Seats\n";
    cout << "2. Model\n";
    cout << "3. Driver Name\n";
    cout << "4. Spetsificheskoe pole\n";
    cout << "Choice: ";
    int sub;
    if (cin >> sub) {
        clearInput();
        if (sub == 1) {
            int seats = readPositiveInt("Enter new number of seats: ");
            car->setSeats(seats);
            cout << "Seats obnovleny!\n";
        } else if (sub == 2) {
            string model = readString("Enter new model: ");
            car->setModel(model);
            cout << "Model obnovlena!\n";
        } else if (sub == 3) {
            string driver = readString("Enter new driver name: ");
            car->setDriverName(driver);
            cout << "Driver obnovlen!\n";
        } else if (sub == 4) {
            string type = car->getType();
            if (type == "Sedan") {
                Sedan* s = dynamic_cast<Sedan*>(car);
                if (s) {
                    int val = readPositiveInt("Has child seat? (1-yes, 2-no): ");
                    s->setHasChildSeat(val == 1);
                    cout << "Detskoe kreslo obnovleno!\n";
                }
            } else if (type == "Minivan") {
                Minivan* m = dynamic_cast<Minivan*>(car);
                if (m) {
                    int val = readPositiveInt("Enter new max luggage: ");
                    m->setMaxLuggage(val);
                    cout << "Max bagazh obnovlen!\n";
                }
            } else if (type == "Electric") {
                ElectricCar* e = dynamic_cast<ElectricCar*>(car);
                if (e) {
                    int charge = readPositiveInt("Enter new charge level (%): ");
                    e->setChargeLevel(charge);
                    cout << "Zaryad obnovlen!\n";
                }
            }
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

void removeCarMenu(TaxiFleet& fleet) {
    if (fleet.getCars().empty()) {
        cout << "Net dostupnyh mashin.\n";
        return;
    }
    cout << "\n!Udalenie mashiny!\n";
    cout << "Dostupno mashin: 0 do " << fleet.getCars().size() - 1 << "\n";
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        cout << i << ". " << fleet.getCars()[i]->getModel()
             << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
    }
    int idx = readIndex("Enter car index to remove: ", fleet.getCars().size());
    Car* carToRemove = fleet.getCars()[idx];
    fleet -= carToRemove;
}

void showOperatorsDemo(TaxiFleet& fleet) {
    cout << "\n!DEMONSTRACIA OPERATOROV!\n";

    if (fleet.getCars().size() < 2) {
        cout << "Nuzhno minimum 2 mashiny dlya demonstratsii.\n";
        return;
    }

    cout << "\n1. Vivod mashin cherez operator <<:\n";
    cout << *fleet.getCars()[0];
    cout << *fleet.getCars()[1];

    cout << "\n2. Sravnenie mashin operatorami ==, <, >:\n";
    if (*fleet.getCars()[0] == *fleet.getCars()[1]) {
        cout << "Mashiny odinakovy po nomeru.\n";
    } else {
        cout << "Mashiny raznye po nomeru.\n";
    }

    if (*fleet.getCars()[0] < *fleet.getCars()[1]) {
        cout << "Pervaya mashina menshe po kolichestvu mest.\n";
    } else if (*fleet.getCars()[0] > *fleet.getCars()[1]) {
        cout << "Pervaya mashina bolshe po kolichestvu mest.\n";
    } else {
        cout << "Mashiny odinakovy po kolichestvu mest.\n";
    }

    cout << "\n3. Proverka podhoda mashiny dlya zakaza (druzh functiya):\n";
    if (isSuitableForOrder(*fleet.getCars()[0], 3)) {
        cout << "Mashina 1 podhodit dlya 3 passazhirov.\n";
    } else {
        cout << "Mashina 1 NE podhodit dlya 3 passazhirov.\n";
    }

    cout << "\n4. Demonstratia operatora -= (udalenie mashiny):\n";
    cout << "Tekushiy spisok mashin:\n";
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        cout << i << ". " << fleet.getCars()[i]->getModel()
             << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
    }

    int idx = readIndex("Viberite index mashiny dlya udaleniya: ", fleet.getCars().size());
    Car* carToRemove = fleet.getCars()[idx];

    cout << "\nUdalaem mashinu: " << carToRemove->getModel() << "...\n";
    fleet -= carToRemove;

    cout << "\nSpisok mashin posle udaleniya:\n";
    if (fleet.getCars().empty()) {
        cout << "Spisok pust.\n";
    } else {
        for (size_t i = 0; i < fleet.getCars().size(); ++i) {
            cout << i << ". " << fleet.getCars()[i]->getModel()
                 << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
        }
    }

    cout << "\n5. Popytka udalit nesushestvuyushuyu mashinu:\n";
    Car* fakeCar = new Sedan("0000 XX-0", "Fake", 0, 0, "none", 0, false);
    fleet -= fakeCar;
    delete fakeCar;

    cout << "\n!KONEC DEMONSTRACII!\n";
}

void showTaxiFleetMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n!TAXIFLEET MENU!\n";
        cout << "1. Pokazat vse mashiny\n";
        cout << "2. Pokazat vse zakazy\n";
        cout << "3. Dobavit mashinu\n";
        cout << "4. Dobavit zakaz\n";
        cout << "5. Proverit zakaz dlya vseh mashin\n";
        cout << "6. Naznachit zakaz na mashinu\n";
        cout << "7. Izmenit harakteristiki mashiny\n";
        cout << "8. Izmenit harakteristiki zakaza\n";
        cout << "9. Udalit mashinu iz taksoparka\n";
        cout << "10. Demonstratia operatorov\n";
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
            case 9: removeCarMenu(fleet); break;
            case 10: showOperatorsDemo(fleet); break;
            case 0: cout << "Vozvrashchenie v Main Menu...\n"; break;
            default: cout << "Neverniy vibor! Poprobuyte snova.\n";
        }
    } while (choice != 0);
}