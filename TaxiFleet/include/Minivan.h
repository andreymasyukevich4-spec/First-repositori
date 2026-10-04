#ifndef MINIVAN_H
#define MINIVAN_H

#include "PassengerCar.h"

class Minivan : public PassengerCar {
private:
    int maxLuggage;

public:
    Minivan();
    Minivan(const string& regNumber, const string& model, int year, int seats,
            const string& driverName, double fuelConsumption, int maxLuggage);

    void setMaxLuggage(int value);
    int getMaxLuggage() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
    virtual string getType() const override;
};

#endif