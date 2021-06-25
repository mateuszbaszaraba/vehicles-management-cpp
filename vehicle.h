//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <iostream>
#include <vector>

#ifndef ELECTRIC_CARS_PROJECT_VEHICLE_H
#define ELECTRIC_CARS_PROJECT_VEHICLE_H

//klasa bazowa Vehicle
class Vehicle {
protected:
    std::string type = "other";
    std::string brand;
    std::string model;
    unsigned short int range;
    unsigned short int power;
    std::string color;
    unsigned short int numberOfSeats;
public:
    virtual void create();
    virtual void show();
    virtual void save();
    Vehicle(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po,
            std::string &co, unsigned short int &nu);
    Vehicle() = default;
    ~Vehicle() = default;

    static bool ifNumeric(std::string &str);

    //getters
    const std::string &getBrand() const;
    const std::string &getModel() const;
    unsigned short getRange() const;
    unsigned short getPower() const;
    const std::string &getColor() const;
    unsigned short getNumberOfSeats() const;

    //setters
    void setBrand();
    void setModel();
    void setRange();
    void setPower();
    void setColor();
    void setNumberOfSeats();

};


#endif //ELECTRIC_CARS_PROJECT_VEHICLE_H
