//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <iostream>
#include "vehicle.h"

#ifndef ELECTRIC_CARS_PROJECT_CAR_H
#define ELECTRIC_CARS_PROJECT_CAR_H

//klasa pochodna Car <- Vehicle
class Car : public Vehicle {
private:
    std::string type = "car";
    long vin;
    bool damaged;
    bool damagedBefore;
    std::string platesNumber;
public:
    void create();
    void show();
    void save();
    Car(std::string ty, std::string br, std::string mo, unsigned short int ra, unsigned short int po, std::string co,
        unsigned short int nu, long vi, bool da, bool db, std::string pl);
    Car();
};


#endif //ELECTRIC_CARS_PROJECT_CAR_H
