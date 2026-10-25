#ifndef SEDAN_H
#define SEDAN_H

#include "PassengerCar.h"

class Sedan : public PassengerCar {
private:
    bool hasSkiHatch;

public:
    Sedan();
    Sedan(const string& regNumber, const string& model, int year, int seats,
          const string& driverName, double fuelConsumption, bool hasSkiHatch);

    void setHasSkiHatch(bool value);
    bool getHasSkiHatch() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
    virtual string getType() const override;
    virtual double calculateCostPerKm() const override;
};

#endif