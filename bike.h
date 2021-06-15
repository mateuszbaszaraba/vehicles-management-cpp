//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <iostream>
#include "vehicle.h"

#ifndef ELECTRIC_CARS_PROJECT_BIKE_H
#define ELECTRIC_CARS_PROJECT_BIKE_H

//klasa pochodna Bike <- Vehicle
class Bike : public Vehicle {
private:
    std::string type = "bike";
    unsigned char gears;
    unsigned short int pushPower;
    int frameNumber;
public:
    void create();
    void show();
    void save();
    Bike(std::string ty, std::string br, std::string mo, unsigned short int ra, unsigned short int po, std::string co,
         unsigned short int nu, unsigned char ge, unsigned short int pu, int fr);
    Bike();
};


#endif //ELECTRIC_CARS_PROJECT_BIKE_H
