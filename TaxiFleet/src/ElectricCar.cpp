#include "../include/ElectricCar.h"

using namespace std;

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
    os << "Reg. nomer: " << regNumber << "\n";
    os << "Model: " << model << "\n";
    os << "God: " << year << "\n";
    os << "Mest: " << seats << "\n";
    os << "Voditel: " << driverName << "\n";
    os << "Emkost batarei: " << batteryCapacity << " kWh\n";
    os << "Zaryad: " << chargeLevel << "%\n";
    os << "Zapas hoda: " << calculateRange() << " km\n";
}

void ElectricCar::readFrom(istream& is) {
    is >> regNumber >> model >> year >> seats >> driverName >> batteryCapacity >> chargeLevel;
}

string ElectricCar::getType() const { return "Electric"; }