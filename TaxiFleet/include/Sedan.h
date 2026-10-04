#ifndef SEDAN_H
#define SEDAN_H

#include "PassengerCar.h"

class Sedan : public PassengerCar {
private:
    bool hasChildSeat;

public:
    Sedan();
    Sedan(const string& regNumber, const string& model, int year, int seats,
          const string& driverName, double fuelConsumption, bool hasChildSeat);

    void setHasChildSeat(bool value);
    bool getHasChildSeat() const;

    virtual void print(ostream& os) const override;
    virtual void readFrom(istream& is) override;
    virtual string getType() const override;
};

#endif