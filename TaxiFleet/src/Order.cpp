#include "../include/Order.h"
#include <iostream>

Order::Order() : fromAddress(""), toAddress(""), passengers(0) {}

Order::Order(const string& fromAddress, const string& toAddress, int passengers)
    : fromAddress(fromAddress), toAddress(toAddress), passengers(passengers) {}

void Order::setFromAddress(const string& fromAddress) { this->fromAddress = fromAddress; }
void Order::setToAddress(const string& toAddress) { this->toAddress = toAddress; }
void Order::setPassengers(int passengers) { this->passengers = passengers; }

string Order::getFromAddress() const { return fromAddress; }
string Order::getToAddress() const { return toAddress; }
int Order::getPassengers() const { return passengers; }

void Order::print() const {
    cout << "Zakaz: " << fromAddress << " -> " << toAddress << "\n";
    cout << "Passengers: " << passengers << "\n";
}