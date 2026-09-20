# My Lab
-Andrey Masyukevich Aleksandrovich
-Variant 17. Taxi Fleet system
-Need to control cars, orders and assign drivers
-lab for creating system of taxi fleet, to manage cars and orders
-LAB1 ADDING CLASSES
-in first part i introduce classes Car, Order, TaxiFleet.
-add structure Date and Time 
-add menu to do some specific task
-LAB2 FRIEND FUNCTIONS AND OVERLOADS
-in second part i introduce operator overloading and friend functions
-add operators ==, <, >, <<, >> for Car and Order
-add operators +=, -= for TaxiFleet
-Sonarcloud to check lab
https://sonarcloud.io/organizations/andreymasyukevich4-spec/projects
-command for create exe file

    g++ -std=c++17 -g -I.
    main.cpp
    src/Car.cpp
    src/Order.cpp
    src/TaxiFleet.cpp
    menu/cpp/MainMenu.cpp
    menu/cpp/CarMenu.cpp
    menu/cpp/OrderMenu.cpp
    menu/cpp/TaxiFleetMenu.cpp
    -o program.exe