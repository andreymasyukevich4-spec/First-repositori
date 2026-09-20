#include "include/TaxiFleet.h"
#include "menu/header/MainMenu.h"
#include <iostream>

using namespace std;

int main() {
    TaxiFleet fleet;

    fleet += Car("4057 AB-7", "Lada Vesta", 2019, 4, "sedan", "Ivanov I.I.");
    fleet += Car("9999 CE-5", "Ford Transit", 2020, 8, "minivan", "Petrov P.P.");
    fleet += Car("9013 KM-7", "Nissan Leaf", 2021, 4, "electric", "Sidorov S.S.");

    fleet.addOrder(Order("Lenina 12", "Mira 45", 3));
    fleet.addOrder(Order("Gagarina 7", "Pushkina 22", 6));
    fleet.addOrder(Order("Sovetskaya 3", "Kirova 88", 9));

    cout << "\n!DEMONSTRACIA OPERATOROV!\n";
    
    cout << "\n1. Vivod mashin cherez operator <<:\n";
    cout << fleet.getCars()[0];
    cout << fleet.getCars()[1];
    
    cout << "\n2. Sravnenie mashin:\n";
    if (fleet.getCars()[0] == fleet.getCars()[1]) {
        cout << "Mashiny odinakovy po nomeru.\n";
    } else {
        cout << "Mashiny raznye po nomeru.\n";
    }
    
    if (fleet.getCars()[0] < fleet.getCars()[1]) {
        cout << "Pervaya mashina menshe po kolichestvu mest.\n";
    } else {
        cout << "Pervaya mashina bolshe ili ravna po kolichestvu mest.\n";
    }
    
    cout << "\n3. Proverka podhoda mashiny dlya zakaza (druzh functiya):\n";
    if (isSuitableForOrder(fleet.getCars()[0], 3)) {
        cout << "Mashina 1 podhodit dlya 3 passazhirov.\n";
    } else {
        cout << "Mashina 1 NE podhodit dlya 3 passazhirov.\n";
    }
    
    cout << "\n4. Udalenie mashiny cherez operator -=:\n";
    cout << "Udalaem mashinu s nomerom 9999 CE-5...\n";
    fleet -= Car("9999 CE-5", "", 0, 0, "", "");
    cout << "Teper v taksoparke " << fleet.getCars().size() << " mashin.\n";
    
    cout << "\n5. Popytka udalit nesushestvuyushuyu mashinu:\n";
    fleet -= Car("0000 XX-0", "", 0, 0, "", "");
    
    cout << "\n!KONEC DEMONSTRACII!\n";

    showMainMenu(fleet);

    return 0;
}