#include "../include/Order.h"

using namespace std;

Order::Order() : fromAddress(""), toAddress(""), passengers(0) {}

Order::Order(const string& fromAddress, const string& toAddress, int passengers)
    : fromAddress(fromAddress), toAddress(toAddress), passengers(passengers) {}

void Order::setFromAddress(const string& fromAddress) { this->fromAddress = fromAddress; }
void Order::setToAddress(const string& toAddress) { this->toAddress = toAddress; }
void Order::setPassengers(int passengers) { this->passengers = passengers; }

string Order::getFromAddress() const { return fromAddress; }
string Order::getToAddress() const { return toAddress; }
int Order::getPassengers() const { return passengers; }

bool Order::operator==(const Order& other) const {
    return fromAddress == other.fromAddress;
}

bool Order::operator<(const Order& other) const {
    return passengers < other.passengers;
}

bool Order::operator>(const Order& other) const {
    return passengers > other.passengers;
}

ostream& operator<<(ostream& os, const Order& order) {
    os << "Order: " << order.fromAddress << " -> " << order.toAddress << "\n";
    os << "  Passengers: " << order.passengers << "\n";
    return os;
}

istream& operator>>(istream& is, Order& order) {
    is >> order.fromAddress >> order.toAddress >> order.passengers;
    return is;
}

bool isOrderForCar(const Order& order, const Car& car) {
    return car.getSeats() >= order.passengers;
}