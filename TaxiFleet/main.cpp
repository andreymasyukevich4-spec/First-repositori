#include "include/TaxiFleet.h"
#include <iostream>

int main() {
    TaxiFleet fleet;

    fleet.addCar(Car("4057 AB-7", "Lada Vesta", 2019, 4, "sedan"));
    fleet.addCar(Car("9999 CE-5", "Ford Transit", 2020, 8, "minivan"));
    fleet.addCar(Car("9013 KM-7", "Nissan Leaf", 2021, 4, "electric"));

    fleet.addOrder(Order("Lenina 12", "Mira 45", 3));
    fleet.addOrder(Order("Gagarina 7", "Pushkina 22", 6));
    fleet.addOrder(Order("Sovetskaya 3", "Kirova 88", 9));

    fleet.printAllCars();
    fleet.printAllOrders();

    cout << "!Order assignment!\n";
    fleet.assignOrder(0);
    fleet.assignOrder(1);
    fleet.assignOrder(2);

    return 0;
}