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
    void create() override;
    void show() override;
    void save() override;
    Car(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po, std::string &co,
        unsigned short int &nu, long &vi, bool &da, bool &db, std::string &pl);
    Car() = default;
    ~Car() = default;

    //getters
    long getVin() const;
    bool getDamaged() const;
    bool getDamagedBefore() const;
    const std::string &getPlatesNumber() const;

    //setters
    void setVin(std::string &tmp);
    void setDamaged(short int &tmp2);
    void setDamagedBefore(short int &tmp2);
    void setPlastesNumber(std::string &tmp);
};


#endif //ELECTRIC_CARS_PROJECT_CAR_H
