#include "../include/Car.h"

using namespace std;

Car::Car() : regNumber(""), model(""), year(0), seats(0), type(""), driverName("") {}

Car::Car(const string& regNumber, const string& model, int year, int seats, const string& type, const string& driverName)
    : regNumber(regNumber), model(model), year(year), seats(seats), type(type), driverName(driverName) {}

void Car::setRegNumber(const string& regNumber) { this->regNumber = regNumber; }
void Car::setModel(const string& model) { this->model = model; }
void Car::setYear(int year) { this->year = year; }
void Car::setSeats(int seats) { this->seats = seats; }
void Car::setType(const string& type) { this->type = type; }
void Car::setDriverName(const string& driverName) { this->driverName = driverName; }

string Car::getRegNumber() const { return regNumber; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
int Car::getSeats() const { return seats; }
string Car::getType() const { return type; }
string Car::getDriverName() const { return driverName; }

void Car::print() const {
    cout << "Avtomobil: " << model << " (" << type << ")\n";
    cout << "  Reg. nomer: " << regNumber << "\n";
    cout << "  God vypuska: " << year << "\n";
    cout << "  Mest: " << seats << "\n";
    cout << "  Voditel: " << driverName << "\n";
}