//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include "car.h"

void Car::create() {
    setBrand();
    setModel();
    setRange();
    setPower();
    setColor();
    setNumberOfSeats();
    setVin();
    setDamaged();
    setDamagedBefore();
    setPlastesNumber();
}

void Car::show() {
    std::cout << std::string(19, '-') << std::endl;
    std::cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nRange: " << getRange()
              << "\nPower: " << getPower() << "\nColor: " << getColor() << "\nNumber of seats: " << getNumberOfSeats()
              << "\nVin: " << getVin() << "\nDamaged: " << getDamaged() << "\nDamaged before: " << getDamagedBefore()
              << "\nPlates number: " << getPlatesNumber() << std::endl;
    std::cout << std::string(19, '-') << std::endl;
}

void Car::save() {
    std::ofstream file("database.bin", std::ios::binary | std::ios::app);

    file.write(type.c_str(), type.size());
    file.write("\0", sizeof(char));

    file.write(brand.c_str(), brand.size());
    file.write("\0", sizeof(char));

    file.write(model.c_str(), model.size());
    file.write("\0", sizeof(char));

    file.write((char*) &range, sizeof(range));

    file.write((char*) &power, sizeof(power));

    file.write(color.c_str(), color.size());
    file.write("\0", sizeof(char));

    file.write((char*) &numberOfSeats, sizeof(numberOfSeats));

    file.write((char*) &vin, sizeof(vin));

    file.write((char*) &damaged, sizeof(damaged));

    file.write((char*) &damagedBefore, sizeof(damagedBefore));

    file.write(platesNumber.c_str(), platesNumber.size());
    file.write("\0", sizeof(char));
}

Car::Car(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po, std::string &co,
         unsigned short int &nu, long &vi, bool &da, bool &db, std::string &pl) {
    type=ty;
    brand=br;
    model=mo;
    range=ra;
    power=po;
    color=co;
    numberOfSeats=nu;
    vin=vi;
    damaged=da;
    damagedBefore=db;
    platesNumber=pl;
}


//getters
long Car::getVin() const {
    return this->vin;
}

bool Car::getDamaged() const {
    return this->damaged;
}

bool Car::getDamagedBefore() const {
    return this->damagedBefore;
}

const std::string &Car::getPlatesNumber() const {
    return this->platesNumber;
}


//setters

void Car::setVin() {
    std::cout << "Vin: ";
    std::string vi;
    std::cin >> vi;
    if(!ifNumeric(vi) || std::stoi(vi) < 0) {
        throw std::runtime_error("Incorrect vin!");
    }
    this->vin = std::stol(vi);

}
void Car::setDamaged() {
    std::cout << "Damaged (1/0): ";
    short int da {};
    std::cin >> da;
    if(da!=0 && da!=1) {
        throw std::runtime_error("Incorrect damage!");
    }
    this->damaged = da;
}

void Car::setDamagedBefore() {
    std::cout << "Was damaged before (1/0): ";
    short int daB;
    std::cin >> daB;
    if(daB<0 || daB>1) {
        throw std::runtime_error("Incorrect damagedBefore!");
    }
    this->damagedBefore = daB;
}
void Car::setPlastesNumber() {
    std::cout << "Plates number: ";
    std::string pl;
    std::cin >> pl;
    if(pl.empty()) {
        throw std::runtime_error("Incorrect plates number!");
    }
    this->platesNumber = pl;
}