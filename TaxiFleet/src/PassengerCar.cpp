#include "../include/PassengerCar.h"

using namespace std;

PassengerCar::PassengerCar() : Car(), fuelConsumption(0.0) {}

PassengerCar::PassengerCar(const string& regNumber, const string& model, int year, int seats,
                           const string& driverName, double fuelConsumption)
    : Car(regNumber, model, year, seats, driverName), fuelConsumption(fuelConsumption) {}

void PassengerCar::setFuelConsumption(double value) { fuelConsumption = value; }
double PassengerCar::getFuelConsumption() const { return fuelConsumption; }

void PassengerCar::print(ostream& os) const {
    os << "Reg. number: " << regNumber << "\n";
    os << "Model: " << model << "\n";
    os << "Year: " << year << "\n";
    os << "Seats: " << seats << "\n";
    os << "Driver: " << driverName << "\n";
    os << "Fuel consumption: " << fuelConsumption << " l/100km\n";
}

void PassengerCar::readFrom(istream& is) {
    is >> regNumber >> model >> year >> seats >> driverName >> fuelConsumption;
}

double PassengerCar::calculateCostPerKm() const {
    return (fuelConsumption * 2.0) / 100.0;
}