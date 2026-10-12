#include "../include/Minivan.h"

using namespace std;

Minivan::Minivan() : PassengerCar(), passengerRowsCount(2) {}

Minivan::Minivan(const string& regNumber, const string& model, int year, int seats,
                 const string& driverName, double fuelConsumption, int passengerRowsCount)
    : PassengerCar(regNumber, model, year, seats, driverName, fuelConsumption),
      passengerRowsCount(passengerRowsCount) {}

void Minivan::setPassengerRowsCount(int value) { passengerRowsCount = value; }
int Minivan::getPassengerRowsCount() const { return passengerRowsCount; }

void Minivan::print(ostream& os) const {
    os << "[MINIVAN]\n";
    PassengerCar::print(os);
    os << "Ryadov sideniy: " << passengerRowsCount << "\n";
}

void Minivan::readFrom(istream& is) {
    PassengerCar::readFrom(is);
    is >> passengerRowsCount;
}

string Minivan::getType() const { return "Minivan"; }