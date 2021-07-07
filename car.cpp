//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include "car.h"

void Car::create() {
    std::cout << "Brand: ";
    std::string temp;
    std::cin >> temp;
    setBrand(temp);

    std::cout << "Model: ";
    std::cin >> temp;
    setModel(temp);

    std::cout << "Range: ";
    std::cin >> temp;
    setRange(temp);

    std::cout << "Power: ";
    std::cin >> temp;
    setPower(temp);

    std::cout << "color: ";
    std::cin >> temp;
    setColor(temp);

    std::cout << "Number of seats: ";
    std::cin >> temp;
    setNumberOfSeats(temp);

    std::cout << "Vin: ";
    std::cin >> temp;
    setVin(temp);

    std::cout << "Damaged (1/0): ";
    short int temp2 {};
    std::cin >> temp2;
    setDamaged(temp2);

    std::cout << "Was damaged before (1/0): ";
    std::cin >> temp2;
    setDamagedBefore(temp2);

    std::cout << "Plates number: ";
    std::cin >> temp;
    setPlastesNumber(temp);
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

void Car::setVin(std::string &tmp) {
    if(!ifNumeric(tmp) || std::stoi(tmp) < 0) {
        throw std::runtime_error("Incorrect vin!");
    }
    this->vin = std::stol(tmp);

}
void Car::setDamaged(short int &tmp2) {
    if(tmp2!=0 && tmp2!=1) {
        throw std::runtime_error("Incorrect damage!");
    }
    this->damaged = tmp2;
}

void Car::setDamagedBefore(short int &tmp2) {
    if(tmp2<0 || tmp2>1) {
        throw std::runtime_error("Incorrect damagedBefore!");
    }
    this->damagedBefore = tmp2;
}
void Car::setPlastesNumber(std::string &tmp) {
    if(tmp.empty()) {
        throw std::runtime_error("Incorrect plates number!");
    }
    this->platesNumber = tmp;
}