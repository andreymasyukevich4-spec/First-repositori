#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

using namespace std;

enum class CarType {
    SEDAN,
    MINIVAN,
    ELECTRIC
};

class Car {
protected:
    string regNumber;
    string model;
    int year;
    int seats;
    string driverName;

public:
    Car();
    Car(const string& regNumber, const string& model, int year, int seats, const string& driverName);
    virtual ~Car() = default;

    void setRegNumber(const string& regNumber);
    void setModel(const string& model);
    void setYear(int year);
    void setSeats(int seats);
    void setDriverName(const string& driverName);

    string getRegNumber() const;
    string getModel() const;
    int getYear() const;
    int getSeats() const;
    string getDriverName() const;

    virtual void print(ostream& os) const = 0;
    virtual void readFrom(istream& is) = 0;
    virtual string getType() const = 0;

    bool operator==(const Car& other) const;
    bool operator<(const Car& other) const;
    bool operator>(const Car& other) const;

    friend ostream& operator<<(ostream& os, const Car& car);
    friend istream& operator>>(istream& is, Car& car);
    friend bool isSuitableForOrder(const Car& car, int passengers);
};

#endif