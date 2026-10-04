#include "include/TaxiFleet.h"
#include "include/Sedan.h"
#include "include/Minivan.h"
#include "include/ElectricCar.h"
#include "menu/header/MainMenu.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    TaxiFleet fleet;

    fleet += new Sedan("4057 AB-7", "Lada Vesta", 2019, 4, "Ivanov I.I.", 7.5, true);
    fleet += new Minivan("9999 CE-5", "Ford Transit", 2020, 8, "Petrov P.P.", 10.2, 500);
    fleet += new ElectricCar("9013 KM-7", "Nissan Leaf", 2021, 4, "Sidorov S.S.", 40.0, 85);

    fleet.addOrder(Order("Lenina 12", "Mira 45", 3));
    fleet.addOrder(Order("Gagarina 7", "Pushkina 22", 6));
    fleet.addOrder(Order("Sovetskaya 3", "Kirova 88", 9));

    showMainMenu(fleet);

    
    return 0;
}