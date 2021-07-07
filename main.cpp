//
// Created by Mateusz Baszaraba on 10/06/2021.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "vehicle.h"
#include "car.h"
#include "bike.h"

void mainMenu(std::vector<std::shared_ptr<Vehicle>> &vehicles);
void showV(std::vector<std::shared_ptr<Vehicle>> &vehicles);
void deleteV(std::vector<std::shared_ptr<Vehicle>> &vehicles);
void saveV(std::vector<std::shared_ptr<Vehicle>> &vehicles);
void readFromFile(std::vector<std::shared_ptr<Vehicle>> &vehicles);

bool isWorking = true;

int main() {
    //vektor zawierający wskaźniki do wprowadzonych pojazdów elektryczne
    std::vector<std::shared_ptr<Vehicle>> vehicles;

    //nieskończona pętla wyświetlająca intefejs głównego menu
    do {
        try {
            mainMenu(vehicles);
        } catch(std::runtime_error &error) {
                std::cout << error.what() << std::endl;
        }
    } while (isWorking);

}

//************************************************************************************************************


//funkcja odpowiedzialna za interfejs głównego menu, gdzie wykonywane sa różne opcje
void mainMenu(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    std::cout << std::string(48, '=') << std::endl;
    std::cout << std::string(10, '*') << " Electric Vehicles Database " << std::string(10, '*') << std::endl;
    std::cout << std::string(48, '=') << std::endl;
    std::cout << "1. Add new vehicle \n2. Show all vehicles \n3. Delete vehicle "
                 "\n4. Save to DataBase \n5. Load from DataBase \n6. Exit" << std::endl;

    int choice;
    std::cin >> choice;

    //sprawdzenie którą opcję wybrał użytkownik
    switch(choice) {
        case 1: {
            //w przypadku wybrania 1. opcji zostaje stworzony wybrany obiekt wybranej klasy
            std::cout << "*Choose one option*\n1.Car\t2.Bike\t3.Other";
            int choice2;
            std::cin >> choice2;

            switch (choice2) {
                case 1: {
                    //tworzenie obiektu klasy Car
                    Car c;
                    c.create();
                    vehicles.push_back(std::make_shared<Car>(c));
                    break;
                }
                case 2: {
                    //tworzenie obiektu klasy Bike
                    Bike b;
                    b.create();
                    vehicles.push_back(std::make_shared<Bike>(b));
                    break;
                }
                case 3: {
                    //tworzenie obiektu klasy Vehicle
                    Vehicle v;
                    v.create();
                    vehicles.push_back(std::make_shared<Vehicle>(v));
                    break;
                }
                default:
                    std::cout << "'" << choice << "'" << "It is not an option!\n";
            }
            break;
        }

        case 2:
            //wyswietlanie wszystkich pojazdów w vectorze vehicles
            showV(vehicles);
            break;
        case 3:
            //usuwanie wybranego pojazdu z vectora vehicles
            if(vehicles.empty()) {
                std::cout << "There are no vehicles!\n";
                break;
            } else {
                deleteV(vehicles);
                break;
            }

        case 4:
            //zapisywanie pojazdów z vectora vehicles do pliku bazy danych
            saveV(vehicles);
            break;
        case 5:
            //odczytywanie pojazdów z pliku bazy danych do vectora
            readFromFile(vehicles);
            break;
        case 6:
            //wyłączenie programu
            isWorking = false;
            break;
        default:
            std::cout << "'" << choice << "'" << "It is not an option!\n";
    }
}

//************************************************************************************************************

//funkcja odpowiedzialna za wyświetlenie pojazdów z vectora vehicles
void showV(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    if(vehicles.empty()) {
        std::cout << "There are no vehicles!\n";
    } else if(vehicles.size() == 1) {
        std::cout << "There is just one vehicle!\n";
    } else {
        std::cout << "There are " << vehicles.size() << " vehicles!\n";
    }
    for(auto const &v : vehicles) {
        v->show();
    }
}

//************************************************************************************************************

//funkcja odpowiedzialna za usuwanie danego pojazdu z vectora vehicles
void deleteV(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    for (int i = 0; i < vehicles.size(); ++i) {
        std::cout << "id: [" << i << "]" << std::endl;
        vehicles[i]->show();
    }
    std::cout << "Which one do you want to delete?\n";
    int n;
    std::cin >> n;
    vehicles.erase(vehicles.begin() + n);
}

//************************************************************************************************************

//funkcja odpowiedzialna za wywałanie w każdym objekcie funkcji składowej save
void saveV(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    //****
    std::string filename = "database.bin";
    std::ofstream file(filename,std::ios::out | std::ios::binary);
    file.close();
    //****
    for(auto const &v : vehicles) {
        v->save();
    }
}

//************************************************************************************************************

//funkcja odpowiedzialna za odczytywanie pojazdów z pliku bazy danych do vectora vehicles
void readFromFile(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    vehicles.clear();
    std::ifstream file("database.bin", std::ios::binary | std::ios::in);
    std::string type;
    while(std::getline(file, type, '\0')) {
        if(strcmp(type.c_str(), "other") == 0) {
            std::string brand;
            std::string model;
            std::string color;
            unsigned short int range;
            unsigned short int power;
            unsigned short int numberOfSeats;

            std::getline(file, brand, '\0');
            std::getline(file, model, '\0');
            file.read((char *) &range, sizeof(range));
            file.read((char *) &power, sizeof(power));
            std::getline(file, color, '\0');
            file.read((char *) &numberOfSeats, sizeof(numberOfSeats));

            Vehicle v1(type, brand, model, range, power, color, numberOfSeats);

            vehicles.push_back(std::make_shared<Vehicle>(v1));
        } else if (strcmp(type.c_str(), "car") == 0) {
            std::string brand;
            std::string model;
            std::string color;
            unsigned short int range;
            unsigned short int power;
            unsigned short int numberOfSeats;

            long vin;
            bool damaged;
            bool damagedBefore;
            std::string platesNumber;

            std::getline(file, brand, '\0');
            std::getline(file, model, '\0');
            file.read((char *) &range, sizeof(range));
            file.read((char *) &power, sizeof(power));
            std::getline(file, color, '\0');
            file.read((char *) &numberOfSeats, sizeof(numberOfSeats));
            file.read((char *) &vin, sizeof(vin));
            file.read((char *) &damaged, sizeof(damaged));
            file.read((char *) &damagedBefore, sizeof(damagedBefore));
            std::getline(file, platesNumber, '\0');

            Car c1(type, brand, model, range, power, color, numberOfSeats, vin, damaged, damagedBefore, platesNumber);

            vehicles.push_back(std::make_shared<Car>(c1));

        } else if (strcmp(type.c_str(), "bike") == 0) {
            std::string brand;
            std::string model;
            std::string color;
            unsigned short int range;
            unsigned short int power;
            unsigned short int numberOfSeats;

            unsigned char gears;
            unsigned short int pushPower;
            int frameNumber;

            std::getline(file, brand, '\0');
            std::getline(file, model, '\0');
            file.read((char *) &range, sizeof(range));
            file.read((char *) &power, sizeof(power));
            std::getline(file, color, '\0');
            file.read((char *) &numberOfSeats, sizeof(numberOfSeats));
            file.read((char *) &gears, sizeof(gears));
            file.read((char *) &pushPower, sizeof(pushPower));
            file.read((char *) &frameNumber, sizeof(frameNumber));

            Bike b1(type, brand, model, range, power, color, numberOfSeats, gears, pushPower, frameNumber);

            vehicles.push_back(std::make_shared<Bike>(b1));
        }
    }
}

