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
    cout << "\n!Adding Sedan!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double fuel = readPositiveInt("Enter Fuel Consumption (l/100km): ");
    int ski = readBool("Has ski hatch? (1-yes, 0-no): ");
    fleet.createSedan(r, m, y, s, d, fuel, ski == 1);
    cout << "Sedan successfully added!\n";
}

void addMinivanMenu(TaxiFleet& fleet) {
    cout << "\n!Adding Minivan!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double fuel = readPositiveInt("Enter Fuel Consumption (l/100km): ");
    int thirdRow = readBool("Has third row? (1-yes, 0-no): ");
    fleet.createMinivan(r, m, y, s, d, fuel, thirdRow == 1);
    cout << "Minivan successfully added!\n";
}

void addElectricCarMenu(TaxiFleet& fleet) {
    cout << "\n!Adding ElectricCar!\n";
    string r = readString("Enter Registration Number: ");
    string m = readString("Enter Model: ");
    int y = readYear("Enter Year: ");
    int s = readPositiveInt("Enter Seats: ");
    string d = readString("Enter Driver Name: ");
    double battery = readPositiveInt("Enter Battery Capacity (kWh): ");
    int charge = readPositiveInt("Enter Charge Level (%): ");
    fleet.createElectricCar(r, m, y, s, d, battery, charge);
    cout << "ElectricCar successfully added!\n";
}

void addCarMenu(TaxiFleet& fleet) {
    cout << "\nWhich car to add?\n";
    cout << "1. Sedan\n";
    cout << "2. Minivan\n";
    cout << "3. ElectricCar\n";
    cout << "0. Cancel\n";
    cout << "Choice: ";
    int choice;
    if (!(cin >> choice)) {
        clearInput();
        cout << "Input error!\n";
        return;
    }
    clearInput();

    switch (choice) {
        case 1: addSedanMenu(fleet); break;
        case 2: addMinivanMenu(fleet); break;
        case 3: addElectricCarMenu(fleet); break;
        case 0: cout << "Cancelled.\n"; break;
        default: cout << "Invalid choice!\n";
    }
}

void addOrderMenu(TaxiFleet& fleet) {
    cout << "\n!Adding order!\n";
    string f = readString("Enter From Address: ");
    string to = readString("Enter To Address: ");
    int p = readPositiveInt("Enter Number of Passengers: ");
    fleet.addOrder(Order(f, to, p));
    cout << "Order successfully added!\n";
}

void checkOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "No available orders.\n";
        return;
    }
    cout << "\n!Checking order against all cars!\n";
    cout << "Available orders: 0 to " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index to check: ", fleet.getOrders().size());
    fleet.checkOrderForAllCars(idx);
}

void assignOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "No available orders.\n";
        return;
    }
    cout << "\n!Assigning order!\n";
    cout << "Available orders: 0 to " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index to assign: ", fleet.getOrders().size());
    fleet.assignOrder(idx);
}

void editCarMenu(TaxiFleet& fleet) {
    if (fleet.getCars().empty()) {
        cout << "No available cars.\n";
        return;
    }
    cout << "\n!Editing car characteristics!\n";
    cout << "Available cars: 0 to " << fleet.getCars().size() - 1 << "\n";
    int idx = readIndex("Enter car index: ", fleet.getCars().size());

    Car* car = fleet.getCars()[idx];
    cout << "\nCurrent car: " << car->getType() << "\n";

    cout << "\nWhat to change?\n";
    cout << "1. Seats\n";
    cout << "2. Model\n";
    cout << "3. Driver Name\n";
    cout << "4. Specific fields\n";
    cout << "Choice: ";
    int sub;
    if (cin >> sub) {
        clearInput();
        if (sub == 1) {
            int seats = readPositiveInt("Enter new number of seats: ");
            car->setSeats(seats);
            cout << "Seats updated!\n";
        } else if (sub == 2) {
            string model = readString("Enter new model: ");
            car->setModel(model);
            cout << "Model updated!\n";
        } else if (sub == 3) {
            string driver = readString("Enter new driver name: ");
            car->setDriverName(driver);
            cout << "Driver updated!\n";
        } else if (sub == 4) {
            string type = car->getType();
            if (type == "Sedan") {
                Sedan* s = dynamic_cast<Sedan*>(car);
                if (s) {
                    cout << "1. Ski hatch\n";
                    cout << "2. Fuel consumption\n";
                    cout << "Choice: ";
                    int c;
                    cin >> c;
                    clearInput();
                    if (c == 1) {
                        int val = readBool("Has ski hatch? (1-yes, 0-no): ");
                        s->setHasSkiHatch(val == 1);
                        cout << "Ski hatch updated!\n";
                    } else if (c == 2) {
                        double fuel = readPositiveInt("Enter new fuel consumption (l/100km): ");
                        s->setFuelConsumption(fuel);
                        cout << "Fuel consumption updated!\n";
                    }
                }
            } else if (type == "Minivan") {
                Minivan* m = dynamic_cast<Minivan*>(car);
                if (m) {
                    cout << "1. Third row\n";
                    cout << "2. Fuel consumption\n";
                    cout << "Choice: ";
                    int c;
                    cin >> c;
                    clearInput();
                    if (c == 1) {
                        int val = readBool("Has third row? (1-yes, 0-no): ");
                        m->setHasThirdRow(val == 1);
                        cout << "Third row updated!\n";
                    } else if (c == 2) {
                        double fuel = readPositiveInt("Enter new fuel consumption (l/100km): ");
                        m->setFuelConsumption(fuel);
                        cout << "Fuel consumption updated!\n";
                    }
                }
            } else if (type == "Electric") {
                ElectricCar* e = dynamic_cast<ElectricCar*>(car);
                if (e) {
                    cout << "1. Charge level\n";
                    cout << "2. Battery capacity\n";
                    cout << "Choice: ";
                    int c;
                    cin >> c;
                    clearInput();
                    if (c == 1) {
                        int charge = readPositiveInt("Enter new charge level (%): ");
                        e->setChargeLevel(charge);
                        cout << "Charge level updated!\n";
                    } else if (c == 2) {
                        double battery = readPositiveInt("Enter new battery capacity (kWh): ");
                        e->setBatteryCapacity(battery);
                        cout << "Battery capacity updated!\n";
                    }
                }
            }
        } else {
            cout << "Invalid choice!\n";
        }
    } else {
        clearInput();
    }
}

void editOrderMenu(TaxiFleet& fleet) {
    if (fleet.getOrders().empty()) {
        cout << "No available orders.\n";
        return;
    }
    cout << "\n!Editing order characteristics!\n";
    cout << "Available orders: 0 to " << fleet.getOrders().size() - 1 << "\n";
    int idx = readIndex("Enter order index: ", fleet.getOrders().size());

    cout << "\nWhat to change?\n";
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
            cout << "From Address updated!\n";
        } else if (sub == 2) {
            string addr = readString("Enter new To Address: ");
            fleet.getOrders()[idx].setToAddress(addr);
            cout << "To Address updated!\n";
        } else if (sub == 3) {
            int p = readPositiveInt("Enter new number of passengers: ");
            fleet.getOrders()[idx].setPassengers(p);
            cout << "Passengers updated!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } else {
        clearInput();
    }
}

void removeCarMenu(TaxiFleet& fleet) {
    if (fleet.getCars().empty()) {
        cout << "No available cars.\n";
        return;
    }
    cout << "\n!Removing car!\n";
    cout << "Available cars: 0 to " << fleet.getCars().size() - 1 << "\n";
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        cout << i << ". " << fleet.getCars()[i]->getModel()
             << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
    }
    int idx = readIndex("Enter car index to remove: ", fleet.getCars().size());
    Car* carToRemove = fleet.getCars()[idx];
    fleet -= carToRemove;
}

void showInheritedFields(TaxiFleet& fleet) {
    cout << "\n=== ONLY INHERITED FIELDS ===\n";
    if (fleet.getCars().empty()) {
        cout << "No cars.\n";
        return;
    }
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        Car* car = fleet.getCars()[i];
        cout << "--- Car " << i << " ---\n";
        cout << "Reg. number: " << car->getRegNumber() << "\n";
        cout << "Model: " << car->getModel() << "\n";
        cout << "Year: " << car->getYear() << "\n";
        cout << "Seats: " << car->getSeats() << "\n";
        cout << "Driver: " << car->getDriverName() << "\n";
    }
}

void showSpecificFields(TaxiFleet& fleet) {
    cout << "\n=== SPECIFIC FIELDS OF DERIVED TYPES ===\n";
    if (fleet.getCars().empty()) {
        cout << "No cars.\n";
        return;
    }
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        Car* car = fleet.getCars()[i];
        string type = car->getType();
        cout << "--- " << type << " ---\n";
        if (type == "Sedan") {
            Sedan* s = dynamic_cast<Sedan*>(car);
            if (s) {
                cout << "Ski hatch: " << (s->getHasSkiHatch() ? "yes" : "no") << "\n";
            }
        } else if (type == "Minivan") {
            Minivan* m = dynamic_cast<Minivan*>(car);
            if (m) {
                cout << "Third row: " << (m->getHasThirdRow() ? "yes" : "no") << "\n";
            }
        } else if (type == "Electric") {
            ElectricCar* e = dynamic_cast<ElectricCar*>(car);
            if (e) {
                cout << "Battery capacity: " << e->getBatteryCapacity() << " kWh\n";
                cout << "Charge level: " << e->getChargeLevel() << "%\n";
                cout << "Range: " << e->calculateRange() << " km\n";
            }
        }
    }
}

void editCommonField(TaxiFleet& fleet) {
    if (fleet.getCars().empty()) {
        cout << "No cars.\n";
        return;
    }
    cout << "\n=== EDIT COMMON FIELD VIA INHERITED SETTER ===\n";
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        cout << i << ". " << fleet.getCars()[i]->getModel()
             << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
    }
    int idx = readIndex("Select car index: ", fleet.getCars().size());
    Car* car = fleet.getCars()[idx];

    cout << "\nWhat to change?\n";
    cout << "1. Model\n";
    cout << "2. Driver\n";
    cout << "3. Year\n";
    cout << "Choice: ";
    int sub;
    cin >> sub;
    clearInput();

    if (sub == 1) {
        string model = readString("Enter new model: ");
        car->setModel(model);
        cout << "Model updated!\n";
    } else if (sub == 2) {
        string driver = readString("Enter new driver: ");
        car->setDriverName(driver);
        cout << "Driver updated!\n";
    } else if (sub == 3) {
        int year = readYear("Enter new year: ");
        car->setYear(year);
        cout << "Year updated!\n";
    } else {
        cout << "Invalid choice!\n";
    }
}

void showCommonFieldsViaGetter(TaxiFleet& fleet) {
    cout << "\n=== COMMON FIELDS VIA INHERITED GETTER ===\n";
    if (fleet.getCars().empty()) {
        cout << "No cars.\n";
        return;
    }
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        Car* car = fleet.getCars()[i];
        cout << car->getModel() << "  " << car->getDriverName() << "\n";
    }
}

void showInheritanceDemo(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n!INHERITANCE DEMONSTRATION!\n";
        cout << "1. Show only inherited fields\n";
        cout << "2. Show specific fields of derived types\n";
        cout << "3. Edit common field via inherited setter\n";
        cout << "4. Show common fields via inherited getter\n";
        cout << "0. Back\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Input error!\n";
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: showInheritedFields(fleet); break;
            case 2: showSpecificFields(fleet); break;
            case 3: editCommonField(fleet); break;
            case 4: showCommonFieldsViaGetter(fleet); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

void showPolymorphicCalculation(TaxiFleet& fleet) {
    cout << "\n!POLYMORPHIC CALCULATION (COST PER 1 KM)!\n";
    if (fleet.getCars().empty()) {
        cout << "No cars.\n";
        return;
    }
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        Car* car = fleet.getCars()[i];
        cout << "Car: " << car->getModel() 
             << " (" << car->getType() << ")\n";
        cout << "  Cost per 1 km: " << car->calculateCostPerKm() << " c.u.\n";
    }
}

void showOperatorsDemo(TaxiFleet& fleet) {
    cout << "\n!OPERATOR OVERLOADING DEMONSTRATION!\n";

    if (fleet.getCars().size() < 2) {
        cout << "Minimum 2 cars required for demonstration.\n";
        return;
    }

    cout << "\n1. Car output via operator <<:\n";
    cout << *fleet.getCars()[0];
    cout << *fleet.getCars()[1];

    cout << "\n2. Comparing cars with ==, <, >:\n";
    if (*fleet.getCars()[0] == *fleet.getCars()[1]) {
        cout << "Cars are equal by number.\n";
    } else {
        cout << "Cars are different by number.\n";
    }

    if (*fleet.getCars()[0] < *fleet.getCars()[1]) {
        cout << "First car is smaller by seats.\n";
    } else if (*fleet.getCars()[0] > *fleet.getCars()[1]) {
        cout << "First car is larger by seats.\n";
    } else {
        cout << "Cars are equal by seats.\n";
    }

    cout << "\n3. Checking car suitability for order (friend function):\n";
    if (isSuitableForOrder(*fleet.getCars()[0], 3)) {
        cout << "Car 1 is suitable for 3 passengers.\n";
    } else {
        cout << "Car 1 is NOT suitable for 3 passengers.\n";
    }

    cout << "\n4. Demonstrating operator -= (removing a car):\n";
    cout << "Current car list:\n";
    for (size_t i = 0; i < fleet.getCars().size(); ++i) {
        cout << i << ". " << fleet.getCars()[i]->getModel()
             << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
    }

    int idx = readIndex("Select car index to remove: ", fleet.getCars().size());
    Car* carToRemove = fleet.getCars()[idx];

    cout << "\nRemoving car: " << carToRemove->getModel() << "...\n";
    fleet -= carToRemove;

    cout << "\nCar list after removal:\n";
    if (fleet.getCars().empty()) {
        cout << "List is empty.\n";
    } else {
        for (size_t i = 0; i < fleet.getCars().size(); ++i) {
            cout << i << ". " << fleet.getCars()[i]->getModel()
                 << " (" << fleet.getCars()[i]->getRegNumber() << ")\n";
        }
    }

    cout << "\n5. Attempting to remove a non-existent car:\n";
    Car* fakeCar = new Sedan("0000 XX-0", "Fake", 0, 0, "none", 0, false);
    fleet -= fakeCar;
    delete fakeCar;

    cout << "\n!END OF DEMONSTRATION!\n";
}

void showTaxiFleetMenu(TaxiFleet& fleet) {
    int choice;
    do {
        cout << "\n!TAXIFLEET MENU!\n";
        cout << "1. Show all cars\n";
        cout << "2. Show all orders\n";
        cout << "3. Add car\n";
        cout << "4. Add order\n";
        cout << "5. Check order against all cars\n";
        cout << "6. Assign order to car\n";
        cout << "7. Edit car characteristics\n";
        cout << "8. Edit order characteristics\n";
        cout << "9. Remove car from fleet\n";
        cout << "10. Operator overloading demonstration (<, >, ==, <<, >>)\n";
        cout << "11. Inheritance demonstration\n";
        cout << "12. Polymorphic calculation\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Input error! Please enter a number.\n";
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
            case 11: showInheritanceDemo(fleet); break;
            case 12: showPolymorphicCalculation(fleet); break;
            case 0: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
}