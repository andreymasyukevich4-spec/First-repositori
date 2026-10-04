#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "Car.h"

class PassengerCar : public Car {
protected:
    double fuelConsumption;

public:
    PassengerCar();
    PassengerCar(const string& regNumber, const string& model, int year, int seats,
                 const string& driverName, double fuelConsumption);
    virtual ~PassengerCar() = default;

    void setFuelConsumption(double value);
    double getFuelConsumption() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
};

#endif