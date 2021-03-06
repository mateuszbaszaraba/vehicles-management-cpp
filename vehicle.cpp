//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include <string>
#include "vehicle.h"

bool Vehicle::ifNumeric(std::string &str) {
    for (auto &i : str) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

void Vehicle::show() {
    std::cout << std::string(19, '-') << std::endl;
    std::cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nRange: " << getRange()
    << "\nPower: " << getPower() << "\nColor: " << getColor() << "\nNumber of seats: " << getNumberOfSeats() << std::endl;
    std::cout << std::string(19, '-') << std::endl;
}

void Vehicle::create() {
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
}

void Vehicle::save() {
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
}

Vehicle::Vehicle(std::string &ty, std::string &br, std::string &mo, unsigned short int &ra, unsigned short int &po,
                 std::string &co, unsigned short int &nu) {
    type=ty;
    brand=br;
    model=mo;
    range=ra;
    power=po;
    color=co;
    numberOfSeats=nu;
}

//setters

void Vehicle::setBrand(std::string &tmp) {
    if(tmp.empty()) {
        throw std::runtime_error("Incorrect brand!");
    }
    this->brand = tmp;
}

void Vehicle::setModel(std::string &tmp) {
    if(tmp.empty()) {
        throw std::runtime_error("Incorrect model!");
    }
    this->model = tmp;
}

void Vehicle::setRange(std::string &tmp) {
    if(!ifNumeric(tmp) || std::stoi(tmp) < 0) {
        throw std::runtime_error("Incorrect range!");
    }

    int result = std::stoi(tmp);
    this->range = static_cast<unsigned short int>(result);
}

void Vehicle::setPower(std::string &tmp) {
    if(!ifNumeric(tmp) || std::stoi(tmp) < 0) {
        throw std::runtime_error("Incorrect power!");
    }

    int result = std::stoi(tmp);
    this->power = static_cast<unsigned short int>(result);
}

void Vehicle::setColor(std::string &tmp) {
    if(tmp.empty()) {
        throw std::runtime_error("Incorrect color!");
    }
    this->color = tmp;
}

void Vehicle::setNumberOfSeats(std::string &tmp) {
    if(!ifNumeric(tmp) || std::stoi(tmp) < 0) {
        throw std::runtime_error("Incorrect number of seats!");
    }

    int result = std::stoi(tmp);
    this->numberOfSeats = static_cast<unsigned short int>(result);
}


//getters
const std::string &Vehicle::getBrand() const {
    return this->brand;
}

const std::string &Vehicle::getModel() const {
    return this->model;
}
unsigned short Vehicle::getRange() const {
    return this->range;
}

unsigned short Vehicle::getPower() const {
    return this->power;
}

const std::string &Vehicle::getColor() const {
    return this->color;
}

unsigned short Vehicle::getNumberOfSeats() const {
    return this->numberOfSeats;
}







