#pragma once 
#include <string>
using namespace std;

class Car{
private:
    string regNumber;
    string model;
    int year;
    int seats;
    string type;

public:
    Car();
    Car(const string& regNumber, const string& model, int year, int seats, const string& type);
    void setRegNumber (const string& regNumber);
    void setModel (const string& model);
    void setYear (int year);
    void setSeats (int Seats);
    void setType(const string& type);
    string getRegNumber() const;
    string getModel() const;
    int getYear() const;
    int getSeats() const;
    string getType() const;
    void print() const;
};
