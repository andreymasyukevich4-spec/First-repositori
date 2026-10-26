#include "../include/ElectricCar.h"
using namespace std;
const double ElectricFullChargePrice = 15.0; 

ElectricCar::ElectricCar() : Car(), batteryCapacity(0.0), chargeLevel(0) {}

ElectricCar::ElectricCar(const string& regNumber, const string& model, int year, int seats,
                         const string& driverName, double batteryCapacity, int chargeLevel)
    : Car(regNumber, model, year, seats, driverName),
      batteryCapacity(batteryCapacity), chargeLevel(chargeLevel) {}

void ElectricCar::setBatteryCapacity(double value) { batteryCapacity = value; }
double ElectricCar::getBatteryCapacity() const { return batteryCapacity; }
void ElectricCar::setChargeLevel(int value) { chargeLevel = value; }
int ElectricCar::getChargeLevel() const { return chargeLevel; }

double ElectricCar::calculateRange() const {
    return batteryCapacity * chargeLevel / 100.0 * 6.0;
}

void ElectricCar::print(ostream& os) const {
    os << "[ELECTRIC]\n";
    os << "Reg. number: " << regNumber << "\n";
    os << "Model: " << model << "\n";
    os << "Year: " << year << "\n";
    os << "Seats: " << seats << "\n";
    os << "Driver: " << driverName << "\n";
    os << "Battery capacity: " << batteryCapacity << " kWh\n";
    os << "Charge level: " << chargeLevel << "%\n";
    os << "Range: " << calculateRange() << " km\n";
}

void ElectricCar::readFrom(istream& is) {
    is >> regNumber >> model >> year >> seats >> driverName >> batteryCapacity >> chargeLevel;
}

string ElectricCar::getType() const { return "Electric"; }

double ElectricCar::calculateCostPerKm() const {
     double maxRange = calculateRange();
    if (maxRange == 0) return 0.0; 
    return ElectricFullChargePrice / maxRange;
}