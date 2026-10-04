#include "../include/Sedan.h"

using namespace std;

Sedan::Sedan() : PassengerCar(), hasChildSeat(false) {}

Sedan::Sedan(const string& regNumber, const string& model, int year, int seats,
             const string& driverName, double fuelConsumption, bool hasChildSeat)
    : PassengerCar(regNumber, model, year, seats, driverName, fuelConsumption),
      hasChildSeat(hasChildSeat) {}

void Sedan::setHasChildSeat(bool value) { hasChildSeat = value; }
bool Sedan::getHasChildSeat() const { return hasChildSeat; }

void Sedan::print(ostream& os) const {
    os << "[SEDAN]\n";
    PassengerCar::print(os);
    os << "Detskoe kreslo: " << (hasChildSeat ? "est" : "net") << "\n";
}

void Sedan::readFrom(istream& is) {
    PassengerCar::readFrom(is);
    is >> hasChildSeat;
}

string Sedan::getType() const { return "Sedan"; }