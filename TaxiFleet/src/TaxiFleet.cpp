#include "../include/TaxiFleet.h"
#include <iostream>

using namespace std;

TaxiFleet::TaxiFleet() {}

void TaxiFleet::addCar(const Car& car) { cars.push_back(car); }
void TaxiFleet::addOrder(const Order& order) { orders.push_back(order); }

void TaxiFleet::checkOrderForAllCars(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= (int)orders.size()) {
        cout << "Oshibka: neverniy index zakaza.\n";
        return;
    }
    
    Order& order = orders[orderIndex];
    cout << "\n--- Proverka zakaza (Passazhirov: " << order.getPassengers() << ") ---\n";
    
    bool hasSuitable = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << i << ". " << cars[i].getModel() << " (" << cars[i].getRegNumber() << "): ";
        if (cars[i].getSeats() >= order.getPassengers()) {
            cout << "MOZHET vipolnit zakaz.\n";
            hasSuitable = true;
        } else {
            cout << "NE MOZHET (mest: " << cars[i].getSeats() << ", nuzhno: " << order.getPassengers() << ").\n";
        }
    }
    
    if (!hasSuitable) {
        cout << ">>> Ni odna mashina ne podhodit dlya etogo zakaza.\n";
    } else {
        cout << ">>> Est podhodyashie mashini. \n";
    }
}

Car* TaxiFleet::findSuitableCar(int passengers) {
    for (auto& car : cars) {
        if (car.getSeats() >= passengers) {
            return &car;
        }
    }
    return nullptr;
}

void TaxiFleet::assignOrder(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= (int)orders.size()) {
        cout << "Oshibka: neverniy index zakaza.\n";
        return;
    }
    
    Order& order = orders[orderIndex];
    Car* car = findSuitableCar(order.getPassengers());
    
    if (car == nullptr) {
        cout << "Net podhodyashego avto dlya zakaza (" << order.getPassengers() << " passazhirov).\n";
        return;
    }
    
    cout << "Zakaz naznachen na avto " << car->getModel() 
         << " (" << car->getRegNumber() << "), Voditel: " << car->getDriverName() << "\n";
}

void TaxiFleet::printAllCars() const {
    cout << "\n!Avtomobili v taksoparke!\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << cars[i];
        cout << "--------------------\n";
    }
}

void TaxiFleet::printAllOrders() const {
    cout << "\n!Zakazi!\n";
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << orders[i];
        cout << "--------------------\n";
    }
}

vector<Car>& TaxiFleet::getCars() { return cars; }
vector<Order>& TaxiFleet::getOrders() { return orders; }

TaxiFleet& TaxiFleet::operator+=(const Car& car) {
    cars.push_back(car);
    return *this;
}

TaxiFleet& TaxiFleet::operator-=(const Car& car) {
    bool found = false;
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (*it == car) {
            cars.erase(it);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Oshibka: mashina s nomerom " << car.getRegNumber() << " ne naydena v taksoparke.\n";
    } else {
        cout << "Mashina " << car.getRegNumber() << " udalena iz taksoparka.\n";
    }
    
    return *this;
}