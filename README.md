# My Lab
Andrey Masyukevich Aleksandrovich
Variant 17. Taxi Fleet system
Need to control cars, orders and assign drivers

LAB1 ADDING CLASSES
in first part i introduce classes Car, Order, TaxiFleet.
add structure Date and Time
add menu to do some specific task

LAB2 FRIEND FUNCTIONS AND OVERLOADS
in second part i introduce operator overloading and friend functions
add operators ==, <, >, <<, >> for Car and Order
add operators +=, -= for TaxiFleet

LAB3 INHERITANCE
in third part i introduce class hierarchy
add base class Car, intermediate class PassengerCar
add derived classes Sedan, Minivan, ElectricCar
add virtual methods print, readFrom, getType
use polymorphism
Sonarcloud to check lab
!https://sonarcloud.io/organizations/andreymasyukevich4-spec/projects

>command for create exe file
    g++ -std=c++17 -g -I. -Iinclude -Imenu/header
    main.cpp
    src/Car.cpp
    src/PassengerCar.cpp
    src/Sedan.cpp
    src/Minivan.cpp
    src/ElectricCar.cpp
    src/Order.cpp
    src/TaxiFleet.cpp
    menu/cpp/TaxiFleetMenu.cpp
    menu/cpp/MainMenu.cpp
    -o program.exe