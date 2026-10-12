#include "include/TaxiFleet.h"
#include "menu/header/MainMenu.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    TaxiFleet fleet;

    fleet.createSedan("4057 AB-7", "Lada Vesta", 2019, 4, "Ivanov I.I.", 7.5, true);
    fleet.createMinivan("9999 CE-5", "Ford Transit", 2020, 8, "Petrov P.P.", 10.2, 3);
    fleet.createElectricCar("9013 KM-7", "Nissan Leaf", 2021, 4, "Sidorov S.S.", 40.0, 85);

    fleet.addOrder(Order("Lenina 12", "Mira 45", 3));
    fleet.addOrder(Order("Gagarina 7", "Pushkina 22", 6));
    fleet.addOrder(Order("Sovetskaya 3", "Kirova 88", 9));

    showMainMenu(fleet);

    cout << "\nNazhmite Enter dlya vyhoda...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}