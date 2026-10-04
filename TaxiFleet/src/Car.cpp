#include "../include/Car.h"

using namespace std;

Car::Car() : regNumber(""), model(""), year(0), seats(0), driverName("") {}

Car::Car(const string& regNumber, const string& model, int year, int seats, const string& driverName)
    : regNumber(regNumber), model(model), year(year), seats(seats), driverName(driverName) {}

void Car::setRegNumber(const string& regNumber) { this->regNumber = regNumber; }
void Car::setModel(const string& model) { this->model = model; }
void Car::setYear(int year) { this->year = year; }
void Car::setSeats(int seats) { this->seats = seats; }
void Car::setDriverName(const string& driverName) { this->driverName = driverName; }

string Car::getRegNumber() const { return regNumber; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
int Car::getSeats() const { return seats; }
string Car::getDriverName() const { return driverName; }

bool Car::operator==(const Car& other) const {
    return regNumber == other.regNumber;
}

bool Car::operator<(const Car& other) const {
    return seats < other.seats;
}

bool Car::operator>(const Car& other) const {
    return seats > other.seats;
}

ostream& operator<<(ostream& os, const Car& car) {
    car.print(os);
    return os;
}

istream& operator>>(istream& is, Car& car) {
    car.readFrom(is);
    return is;
}

bool isSuitableForOrder(const Car& car, int passengers) {
    return car.seats >= passengers;
}