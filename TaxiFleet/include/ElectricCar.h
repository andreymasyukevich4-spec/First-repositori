#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
    double batteryCapacity;
    int chargeLevel;

public:
    ElectricCar();
    ElectricCar(const string& regNumber, const string& model, int year, int seats,
                const string& driverName, double batteryCapacity, int chargeLevel);

    void setBatteryCapacity(double value);
    double getBatteryCapacity() const;
    void setChargeLevel(int value);
    int getChargeLevel() const;

    double calculateRange() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
    virtual string getType() const override;
};

#endif