#include "../include/TaxiFleet.h"
#include "../include/Sedan.h"
#include "../include/Minivan.h"
#include "../include/ElectricCar.h"
#include <iostream>

using namespace std;

TaxiFleet::TaxiFleet() {}

TaxiFleet::~TaxiFleet() {
    for (auto car : cars) {
        delete car;
    }
    cars.clear();
}

void TaxiFleet::createSedan(const string& regNumber, const string& model, int year, int seats,
                             const string& driverName, double fuelConsumption, bool hasSkiHatch) {
    cars.push_back(new Sedan(regNumber, model, year, seats, driverName, fuelConsumption, hasSkiHatch));
}

void TaxiFleet::createMinivan(const string& regNumber, const string& model, int year, int seats,
                               const string& driverName, double fuelConsumption, bool hasThirdRow) {
    cars.push_back(new Minivan(regNumber, model, year, seats, driverName, fuelConsumption, hasThirdRow));
}

void TaxiFleet::createElectricCar(const string& regNumber, const string& model, int year, int seats,
                                   const string& driverName, double batteryCapacity, int chargeLevel) {
    cars.push_back(new ElectricCar(regNumber, model, year, seats, driverName, batteryCapacity, chargeLevel));
}

void TaxiFleet::addOrder(const Order& order) {
    orders.push_back(order);
}

void TaxiFleet::checkOrderForAllCars(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= (int)orders.size()) {
        cout << "Error: invalid order index.\n";
        return;
    }

    Order& order = orders[orderIndex];
    cout << "\n--- Order Check (Passengers: " << order.getPassengers() << ") ---\n";

    bool hasSuitable = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << i << ". " << cars[i]->getModel() << " (" << cars[i]->getRegNumber() << "): ";
        if (cars[i]->getSeats() >= order.getPassengers()) {
            cout << "CAN fulfill the order.\n";
            hasSuitable = true;
        } else {
            cout << "CANNOT (seats: " << cars[i]->getSeats() << ", needed: " << order.getPassengers() << ").\n";
        }
    }

    if (!hasSuitable) {
        cout << ">>> No car is suitable for this order.\n";
    } else {
        cout << ">>> There are suitable cars.\n";
    }
}

Car* TaxiFleet::findSuitableCar(int passengers) {
    for (auto car : cars) {
        if (car->getSeats() >= passengers) {
            return car;
        }
    }
    return nullptr;
}

void TaxiFleet::assignOrder(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= (int)orders.size()) {
        cout << "Error: invalid order index.\n";
        return;
    }

    Order& order = orders[orderIndex];
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
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << *cars[i];
        cout << "--------------------\n";
    }
}

void TaxiFleet::printAllOrders() const {
    cout << "\n!Orders!\n";
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << "Index: " << i << "\n";
        cout << orders[i];
        cout << "--------------------\n";
    }
}

TaxiFleet& TaxiFleet::operator+=(Car* car) {
    cars.push_back(car);
    return *this;
}

TaxiFleet& TaxiFleet::operator-=(Car* car) {
    bool found = false;
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (**it == *car) {
            string removedNumber = (*it)->getRegNumber(); 
            delete *it;
            cars.erase(it);
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