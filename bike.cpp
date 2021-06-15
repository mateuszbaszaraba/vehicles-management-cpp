//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <fstream>
#include "bike.h"


void Bike::create() {
    std::cout << "Brand: "; std::cin >> brand;
    std::cout << "Model: "; std::cin >> model;
    std::cout << "Range: "; std::cin >> range;
    std::cout << "Power: "; std::cin >> power;
    std::cout << "Color: "; std::cin >> color;
    std::cout << "Number of seats: "; std::cin >> numberOfSeats;
    std::cout << "Gears: "; std::cin >> gears;
    std::cout << "Push power: "; std::cin >> pushPower;
    std::cout << "Frame number: "; std::cin >> frameNumber;
}

void Bike::show() {
    std::cout << std::string(19, '-') << std::endl;
    std::cout << "Brand: " << brand << "\nModel: " << model << "\nRange: " << range
              << "\nPower: " << power << "\nColor: " << color << "\nNumber of seats: " << numberOfSeats
              << "\nGears: " << gears << "\nPush power: " << pushPower << "\nFrame number: " << frameNumber << std::endl;
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

Bike::Bike(std::string ty, std::string br, std::string mo, unsigned short int ra, unsigned short int po, std::string co,
           unsigned short int nu, unsigned char ge, unsigned short int pu, int fr) {
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

Bike::Bike() {};