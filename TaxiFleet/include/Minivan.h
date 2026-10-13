#ifndef MINIVAN_H
#define MINIVAN_H

#include "PassengerCar.h"

class Minivan : public PassengerCar {
private:
    bool hasThirdRow;

public:
    Minivan();
    Minivan(const string& regNumber, const string& model, int year, int seats,
            const string& driverName, double fuelConsumption, bool hasThirdRow);

    void setHasThirdRow(bool value);
    bool getHasThirdRow() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
    virtual string getType() const override;
};

#endif