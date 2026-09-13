#pragma once
#include <vector>
#include "Car.h"
#include "Order.h"
using namespace std;

class TaxiFleet {
private:
    vector<Car> cars;
    vector<Order> orders;

public:
    TaxiFleet();
    void addCar(const Car& car);
    void addOrder(const Order& order);
    Car* findSuitableCar(int passengers);
    void assignOrder(int orderIndex);
    void printAllCars() const;
    void printAllOrders() const;
};