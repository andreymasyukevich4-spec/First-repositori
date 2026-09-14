#include "include/TaxiFleet.h"
#include "Header/MainMenu.h"
#include <iostream>

using namespace std;

int main() {
    TaxiFleet fleet;

    fleet.addCar(Car("4057 AB-7", "Lada Vesta", 2019, 4, "sedan", "Ivanov I.I."));
    fleet.addCar(Car("9999 CE-5", "Ford Transit", 2020, 8, "minivan", "Petrov P.P."));
    fleet.addCar(Car("9013 KM-7", "Nissan Leaf", 2021, 4, "electric", "Sidorov S.S."));

    fleet.addOrder(Order("Lenina 12", "Mira 45", 3));
    fleet.addOrder(Order("Gagarina 7", "Pushkina 22", 6));
    fleet.addOrder(Order("Sovetskaya 3", "Kirova 88", 9));

    showMainMenu(fleet);

    return 0;
}