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
    void create() override;
    void show() override;
    void save() override;
    Bike(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po, std::string &co,
         unsigned short int &nu, unsigned char &ge, unsigned short int &pu, int &fr);
    Bike() = default;
    ~Bike() = default;

    //getters
    unsigned char getGears() const;
    unsigned short int getPushPower() const;
    int getFrameNumber() const;

    //setters
    void setGears(char &temp3);
    void setPushPower(std::string &temp);
    void setFrameNumber(std::string &temp);
};


#endif //ELECTRIC_CARS_PROJECT_BIKE_H
