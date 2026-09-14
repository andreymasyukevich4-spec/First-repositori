#include "../include/TaxiFleet.h"

using namespace std;

TaxiFleet::TaxiFleet() {}

void TaxiFleet::addCar(const Car& car) { cars.push_back(car); }
void TaxiFleet::addOrder(const Order& order) { orders.push_back(order); }

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
        cout << "Oshibka: nevernyi index zakaza.\n";
        return;
    }
    Order& order = orders[orderIndex];
    Car* car = findSuitableCar(order.getPassengers());

    if (car == nullptr) {
        cout << "Net podhodyashego avto dlya zakaza (" 
             << order.getPassengers() << " passengers).\n";
        return;
    }
    cout << "Zakaz naznachen na avto " << car->getModel()
         << " (" << car->getRegNumber() << "), Voditel: " << car->getDriverName() << "\n";
}

void TaxiFleet::printAllCars() const {
    cout << "\n!Avtomobili v taksoparke!\n";
    for (const auto& car : cars) {
        car.print();
        cout << "-----------------\n";
    }
}

void TaxiFleet::printAllOrders() const {
    cout << "\n!Zakazy!\n";
    for (const auto& order : orders) {
        order.print();
        cout << "-----------------\n";
    }
}

vector<Car>& TaxiFleet::getCars() { return cars; }
vector<Order>& TaxiFleet::getOrders() { return orders; }