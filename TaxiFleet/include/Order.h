#pragma once
#include <string>
#include <iostream>

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

    void print() const;
};