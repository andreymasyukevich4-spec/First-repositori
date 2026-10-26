# Taxi Fleet Management System

**Student:** Andrey Masyukevich Aleksandrovich  
**Variant:** 17  

**About the project:**  
A C++ console application for managing a taxi fleet. The system allows users to add various types of cars (sedans, minivans, electric cars), create client orders, assign available cars to orders, and calculate the cost of a trip per kilometer.

---

### LAB 1: Adding Classes
Introduced the core classes: `Car`, `Order`, and the managing class `TaxiFleet`. Added a console menu for basic operations (adding cars and orders, viewing lists).

### LAB 2: Friend Functions and Operator Overloading
Implemented operator overloading and friend functions. Added comparison operators (`==`, `<`, `>`), input/output operators (`<<`, `>>`) for `Car` and `Order`, and operators `+=`, `-=` for `TaxiFleet`.

### LAB 3: Inheritance
Built a class hierarchy:
*   Base class: `Car`
*   Intermediate class: `PassengerCar` (for fuel-powered cars)
*   Derived classes: `Sedan`, `Minivan`, `ElectricCar`

### LAB 4: Polymorphism and Abstract Classes
Made the base class abstract by adding virtual methods (`print`, `readFrom`, `getType`). Implemented dynamic polymorphism through a collection of pointers (`vector<Car*>`) and added a specific calculation method (`calculateCostPerKm`) that behaves differently for each car type.

---

**SonarCloud Check:**  
[https://sonarcloud.io/organizations/andreymasyukevich4-spec/projects](https://sonarcloud.io/organizations/andreymasyukevich4-spec/projects)

**Build Command:**
```bash
g++ -std=c++17 -g -I. -Iinclude -Imenu/header main.cpp src/*.cpp menu/cpp/*.cpp -o program.exe