#include "../include/Sedan.h"
using namespace std;
const double SedanFuelPrice = 2.0;
const double KmPerOneHundred = 100.0;

Sedan::Sedan() : PassengerCar(), hasSkiHatch(false) {}

Sedan::Sedan(const string& regNumber, const string& model, int year, int seats,
             const string& driverName, double fuelConsumption, bool hasSkiHatch)
    : PassengerCar(regNumber, model, year, seats, driverName, fuelConsumption),
      hasSkiHatch(hasSkiHatch) {}

void Sedan::setHasSkiHatch(bool value) { hasSkiHatch = value; }
bool Sedan::getHasSkiHatch() const { return hasSkiHatch; }

void Sedan::print(ostream& os) const {
    os << "[SEDAN]\n";
    PassengerCar::print(os);
    os << "Ski hatch: " << (hasSkiHatch ? "yes" : "no") << "\n";
}

void Sedan::readFrom(istream& is) {
    PassengerCar::readFrom(is);
    is >> hasSkiHatch;
}

string Sedan::getType() const { return "Sedan"; }

double Sedan::calculateCostPerKm() const {
    return (fuelConsumption * SedanFuelPrice) / KmPerOneHundred;
}