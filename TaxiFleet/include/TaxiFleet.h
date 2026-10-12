#ifndef TAXIFLEET_H
#define TAXIFLEET_H

#include <vector>
#include <string>
#include "Car.h"
#include "Order.h"

using namespace std;

class TaxiFleet {
private:
    vector<Car*> cars;
    vector<Order> orders;

public:
    TaxiFleet();
    ~TaxiFleet();

    void createSedan(const string& regNumber, const string& model, int year, int seats,
                     const string& driverName, double fuelConsumption, bool hasSkiHatch);
    void createMinivan(const string& regNumber, const string& model, int year, int seats,
                       const string& driverName, double fuelConsumption, int passengerRowsCount);
    void createElectricCar(const string& regNumber, const string& model, int year, int seats,
                           const string& driverName, double batteryCapacity, int chargeLevel);

    void addOrder(const Order& order);

    void checkOrderForAllCars(int orderIndex);
    Car* findSuitableCar(int passengers);
    void assignOrder(int orderIndex);

    void printAllCars() const;
    void printAllOrders() const;

    vector<Car*>& getCars() { return cars; }
    vector<Order>& getOrders() { return orders; }

    TaxiFleet& operator+=(Car* car);
    TaxiFleet& operator-=(Car* car);
};

#endif