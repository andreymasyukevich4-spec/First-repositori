#include "../include/Minivan.h"
using namespace std;
const double MinivanFuelPrice = 2.2;
const double KmPerOneHundred = 100.0;

Minivan::Minivan() : PassengerCar(), hasThirdRow(false) {}

Minivan::Minivan(const string& regNumber, const string& model, int year, int seats,
                 const string& driverName, double fuelConsumption, bool hasThirdRow)
    : PassengerCar(regNumber, model, year, seats, driverName, fuelConsumption),
      hasThirdRow(hasThirdRow) {}

void Minivan::setHasThirdRow(bool value) { hasThirdRow = value; }
bool Minivan::getHasThirdRow() const { return hasThirdRow; }

void Minivan::print(ostream& os) const {
    os << "[MINIVAN]\n";
    PassengerCar::print(os);
    os << "Third row: " << (hasThirdRow ? "yes" : "no") << "\n";
}

void Minivan::readFrom(istream& is) {
    PassengerCar::readFrom(is);
    is >> hasThirdRow;
}

string Minivan::getType() const { return "Minivan"; }

double Minivan::calculateCostPerKm() const {
    return (fuelConsumption * MinivanFuelPrice) / KmPerOneHundred;
}