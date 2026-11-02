#ifndef TAXIFLEET_H
#define TAXIFLEET_H

#include <vector>
#include <string>
#include "Car.h"
#include "Order.h"
#include "Collection.h"

using namespace std;

class TaxiFleet {
private:
    Collection<Car*> cars;
    Collection<Order> orders;

public:
    TaxiFleet();
    ~TaxiFleet();

    void addSedan(const string& regNumber, const string& model, int year, int seats,
                  const string& driverName, double fuelConsumption, bool hasSkiHatch);

    void addMinivan(const string& regNumber, const string& model, int year, int seats,
                    const string& driverName, double fuelConsumption, bool hasThirdRow);

    void addElectricCar(const string& regNumber, const string& model, int year, int seats,
                        const string& driverName, double batteryCapacity, int chargeLevel);

    void addOrder(const Order& order);

    void checkOrderForAllCars(int orderIndex);
    Car* findSuitableCar(int passengers);
    void assignOrder(int orderIndex);

    void printAllCars() const;
    void printAllOrders() const;

    Collection<Car*>& getCars() { return cars; }
    Collection<Order>& getOrders() { return orders; }

    TaxiFleet& operator+=(Car* car);
    TaxiFleet& operator-=(Car* car);
};

#endif