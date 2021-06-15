//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include "vehicle.h"

void Vehicle::show() {
    std::cout << std::string(19, '-') << std::endl;
    std::cout << "Brand: " << brand << "\nModel: " << model << "\nRange: " << range
    << "\nPower: " << power << "\nColor: " << color << "\nNumber of seats: " << numberOfSeats << std::endl;
    std::cout << std::string(19, '-') << std::endl;
}

void Vehicle::create() {
    std::cout << "Brand: "; std::cin >> brand;
    std::cout << "Model: "; std::cin >> model;
    std::cout << "Range: "; std::cin >> range;
    std::cout << "Power: "; std::cin >> power;
    std::cout << "Color: "; std::cin >> color;
    std::cout << "Number of seats: "; std::cin >> numberOfSeats;
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

Vehicle::Vehicle(std::string ty, std::string br, std::string mo, unsigned short int ra, unsigned short int po,
                 std::string co, unsigned short int nu) {
    type=ty;
    brand=br;
    model=mo;
    range=ra;
    power=po;
    color=co;
    numberOfSeats=nu;
}

Vehicle::Vehicle() {};