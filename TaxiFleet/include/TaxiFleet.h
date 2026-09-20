#ifndef TAXIFLEET_H
#define TAXIFLEET_H

#include <vector>
#include <string>
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
    
    void checkOrderForAllCars(int orderIndex); 
    Car* findSuitableCar(int passengers);
    void assignOrder(int orderIndex);
    
    void printAllCars() const;
    void printAllOrders() const;
    
    vector<Car>& getCars() { return cars; }
    vector<Order>& getOrders() { return orders; }

    TaxiFleet& operator+=(const Car& car);
    TaxiFleet& operator-=(const Car& car);
};

#endif