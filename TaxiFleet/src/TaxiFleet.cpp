#include "../include/TaxiFleet.h"
#include "../include/Sedan.h"
#include "../include/Minivan.h"
#include "../include/ElectricCar.h"
#include <iostream>

using namespace std;

TaxiFleet::TaxiFleet() {}

TaxiFleet::~TaxiFleet() {
    for (int i = 0; i < cars.size(); ++i) {
        delete cars.get(i);
    }
}

void TaxiFleet::addSedan(const string& regNumber, const string& model, int year, int seats,
                          const string& driverName, double fuelConsumption, bool hasSkiHatch) {
    cars.add(new Sedan(regNumber, model, year, seats, driverName, fuelConsumption, hasSkiHatch));
}

void TaxiFleet::addMinivan(const string& regNumber, const string& model, int year, int seats,
                            const string& driverName, double fuelConsumption, bool hasThirdRow) {
    cars.add(new Minivan(regNumber, model, year, seats, driverName, fuelConsumption, hasThirdRow));
}

void TaxiFleet::addElectricCar(const string& regNumber, const string& model, int year, int seats,
                                const string& driverName, double batteryCapacity, int chargeLevel) {
    cars.add(new ElectricCar(regNumber, model, year, seats, driverName, batteryCapacity, chargeLevel));
}

void TaxiFleet::addOrder(const Order& order) {
    orders.add(order);
}

void TaxiFleet::checkOrderForAllCars(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= orders.size()) {
        cout << "Error: invalid order index.\n";
        return;
    }

    Order& order = const_cast<Order&>(orders.get(orderIndex));
    cout << "\n--- Order Check (Passengers: " << order.getPassengers() << ") ---\n";

    bool hasSuitable = false;
    for (int i = 0; i < cars.size(); ++i) {
        Car* car = cars.get(i);
        cout << i << ". " << car->getModel() << " (" << car->getRegNumber() << "): ";
        if (car->getSeats() >= order.getPassengers()) {
            cout << "CAN fulfill the order.\n";
            hasSuitable = true;
        } else {
            cout << "CANNOT (seats: " << car->getSeats() << ", needed: " << order.getPassengers() << ").\n";
        }
    }

    if (!hasSuitable) {
        cout << ">>> No car is suitable for this order.\n";
    } else {
        cout << ">>> There are suitable cars.\n";
    }
}

Car* TaxiFleet::findSuitableCar(int passengers) {
    for (int i = 0; i < cars.size(); ++i) {
        Car* car = cars.get(i);
        if (car->getSeats() >= passengers) {
            return car;
        }
    }
    return nullptr;
}

void TaxiFleet::assignOrder(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= orders.size()) {
        cout << "Error: invalid order index.\n";
        return;
    }

    Order& order = const_cast<Order&>(orders.get(orderIndex));
    Car* car = findSuitableCar(order.getPassengers());

    if (car == nullptr) {
        cout << "No suitable car for order (" << order.getPassengers() << " passengers).\n";
        return;
    }

    cout << "Order assigned to car " << car->getModel()
         << " (" << car->getRegNumber() << "), Driver: " << car->getDriverName() << "\n";
}

void TaxiFleet::printAllCars() const {
    cout << "\n!Cars in the fleet!\n";
    for (int i = 0; i < cars.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << *cars.get(i);
        cout << "--------------------\n";
    }
}

void TaxiFleet::printAllOrders() const {
    cout << "\n!Orders!\n";
    for (int i = 0; i < orders.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << orders.get(i);
        cout << "--------------------\n";
    }
}

TaxiFleet& TaxiFleet::operator+=(Car* car) {
    cars.add(car);
    return *this;
}

TaxiFleet& TaxiFleet::operator-=(Car* car) {
    bool found = false;
    for (int i = 0; i < cars.size(); ++i) {
        if (*cars.get(i) == *car) {
            string removedNumber = cars.get(i)->getRegNumber();
            delete cars.get(i);
            cars.remove(i);
            found = true;
            cout << "Car " << removedNumber << " removed from the fleet.\n";
            break;
        }
    }

    if (!found) {
        cout << "Error: car with number " << car->getRegNumber() << " not found in the fleet.\n";
    }

    return *this;
}