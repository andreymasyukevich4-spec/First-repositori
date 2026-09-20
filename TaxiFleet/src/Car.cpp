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

bool Car::operator==(const Car& other) const{
    return regNumber == other.regNumber;
}

bool Car::operator==(const Car& other) const{
    return seats < other.seats;
}

bool Car::operator==(const Car& other) const{
    return seats > other.seats;
}

ostream& operator<<(ostream& os, const Car& car){
    os << "Avtomobil: " << car.model << " (" << car.type << ")\n";
    os << "  Reg. nomer: " << car.regNumber << "\n";
    os << "  God vypuska: " << car.year << "\n";
    os << "  Mest: " << car.seats << "\n";
    os << "  Voditel: " << car.driverName << "\n";
return os;
}

istream& operator>>(istream& is, Car& car) {
    cout << "Enter Registration Number: ";
    is >> car.regNumber;
    cout << "Enter Model: ";
    is >> car.model;
    cout << "Enter Year: ";
    is >> car.year;
    cout << "Enter Seats: ";
    is >> car.seats;
    cout << "Enter Type: ";
    is >> car.type;
    cout << "Enter Driver Name: ";
    is >> car.driverName;
    return is;
}

bool isSuitableForOrder(const Car& car, int passengers) {
    return car.seats >= passengers;
}