#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car {
private:
    string regNumber;
    string model;
    int year;
    int seats;
    string type;
    string driverName;

public:
    Car();
    Car(const string& regNumber, const string& model, int year, int seats, const string& type, const string& driverName);

    void setRegNumber(const string& regNumber);
    void setModel(const string& model);
    void setYear(int year);
    void setSeats(int seats);
    void setType(const string& type);
    void setDriverName(const string& driverName);

    string getRegNumber() const;
    string getModel() const;
    int getYear() const;
    int getSeats() const;
    string getType() const;
    string getDriverName() const;

    void print() const;
};