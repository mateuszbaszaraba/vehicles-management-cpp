//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include "bike.h"


void Bike::create() {
    setBrand();
    setModel();
    setRange();
    setPower();
    setColor();
    setNumberOfSeats();
    setGears();
    setPushPower();
    setFrameNumber();
}

void Bike::show() {
    std::cout << std::string(19, '-') << std::endl;
    std::cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nRange: " << getRange()
              << "\nPower: " << getPower() << "\nColor: " << getColor() << "\nNumber of seats: " << getNumberOfSeats()
              << "\nGears: " << getGears() << "\nPush power: " << getPushPower() << "\nFrame number: " << getFrameNumber()
              << std::endl;
    std::cout << std::string(19, '-') << std::endl;
}

void Bike::save() {
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

    file.write((char*) &gears, sizeof(gears));

    file.write((char*) &pushPower, sizeof(pushPower));

    file.write((char*) &frameNumber, sizeof(frameNumber));

}

Bike::Bike(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po, std::string &co,
           unsigned short int &nu, unsigned char &ge, unsigned short int &pu, int &fr) {
    type=ty;
    brand=br;
    model=mo;
    range=ra;
    power=po;
    color=co;
    numberOfSeats=nu;
    gears=ge;
    pushPower=pu;
    frameNumber=fr;
}


//getters
unsigned char Bike::getGears() const {
    return this->gears;
}

unsigned short int Bike::getPushPower() const {
    return this->pushPower;
}

int Bike::getFrameNumber() const {
    return this->frameNumber;
}


//setters

void Bike::setGears() {
    std::cout << "Gears: ";
    char ge;
    std::cin >> ge;
    if(ge<0) {
        throw std::runtime_error("Incorrect number of gears!");
    }
    this->gears = ge;
}

void Bike::setPushPower() {
    std::cout << "Push Power: ";
    std::string pu;
    std::cin >> pu;

    if(!ifNumeric(pu) || std::stoi(pu) < 0) {
        throw std::runtime_error("Incorrect push power!");
    }

    int result = std::stoi(pu);
    this->pushPower = static_cast<unsigned short int>(result);
}

void Bike::setFrameNumber() {
    std::cout << "Frame Number: ";
    std::string fr;
    std::cin >> fr;

    if(!ifNumeric(fr) || std::stoi(fr) < 0) {
        throw std::runtime_error("Incorrect frame number!");
    }

    int result = std::stoi(fr);
    this->frameNumber = static_cast<unsigned short int>(result);
}