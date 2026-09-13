#include "../include/Car.h"
#include <iostream>

Car::Car() : regNumber(""), model(""), year(0), seats(0), type("") {}

Car::Car(const string& regNumber, const string& model, int year, int seats, const string& type)
 : regNumber(regNumber), model(model), year(year), seats(seats), type(type) {} 

void Car::setRegNumber(const string& regNumber) { this->regNumber = regNumber; }
void Car::setModel(const string& model) { this->model = model; }
void Car::setYear(int year) { this->year = year; }
void Car::setSeats(int seats) { this->seats = seats; }
void Car::setType(const string& type) { this->type = type; }

string Car::getRegNumber() const { return regNumber; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
int Car::getSeats() const { return seats; }
string Car::getType() const { return type; }

void Car::print() const {
    cout << "Avtomobil: " << model << " (" << type << ")\n";
    cout << "  Reg. nomer: " << regNumber << "\n";
    cout << "  God vipuska: " << year << "\n";
    cout << "  Mest: " << seats << "\n";
}