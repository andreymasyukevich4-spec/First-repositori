#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
#include "Car.h"

using namespace std;

class Order {
private:
    string fromAddress;
    string toAddress;
    int passengers;

public:
    Order();
    Order(const string& fromAddress, const string& toAddress, int passengers);

    void setFromAddress(const string& fromAddress);
    void setToAddress(const string& toAddress);
    void setPassengers(int passengers);

    string getFromAddress() const;
    string getToAddress() const;
    int getPassengers() const;

    bool operator==(const Order& other) const;
    bool operator<(const Order& other) const;
    bool operator>(const Order& other) const;

    friend ostream& operator<<(ostream& os, const Order& order);
    friend istream& operator>>(istream& is, Order& order);
    friend bool isOrderForCar(const Order& order, const Car& car);
};

#endif