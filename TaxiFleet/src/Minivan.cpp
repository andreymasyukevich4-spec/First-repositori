#include "../include/Minivan.h"

using namespace std;

Minivan::Minivan() : PassengerCar(), maxLuggage(0) {}

Minivan::Minivan(const string& regNumber, const string& model, int year, int seats,
                 const string& driverName, double fuelConsumption, int maxLuggage)
    : PassengerCar(regNumber, model, year, seats, driverName, fuelConsumption),
      maxLuggage(maxLuggage) {}

void Minivan::setMaxLuggage(int value) { maxLuggage = value; }
int Minivan::getMaxLuggage() const { return maxLuggage; }

void Minivan::print(ostream& os) const {
    os << "[MINIVAN]\n";
    PassengerCar::print(os);
    os << "Maks. bagazh: " << maxLuggage << " l\n";
}

void Minivan::readFrom(istream& is) {
    PassengerCar::readFrom(is);
    is >> maxLuggage;
}

string Minivan::getType() const { return "Minivan"; }