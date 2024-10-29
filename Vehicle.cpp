#include "Vehicle.h"
using namespace std;


Vehicle::Vehicle(float p, int speed, int yr, string col)
    : price(p), maxSpeed(speed), year(yr), color(col) {}

float Vehicle::getPrice() const { return price; }
int Vehicle::getMaxSpeed() const { return maxSpeed; }
int Vehicle::getYear() const { return year; }
string Vehicle::getColor() const { return color; }
void Vehicle::setPrice(float p) { price = p; }
void Vehicle::setColor(string col) { color = col; }


Car::Car(float p, int speed, int yr, string col, int seats)
    : Vehicle(p, speed, yr, col), seatCount(seats) {}

void Car::showInfo() const {
    cout << "Car - Price: " << price << ", Max Speed: " << maxSpeed
        << ", Year: " << year << ", Color: " << color
        << ", Seats: " << seatCount << "\n";
}

string Car::getType() const { return "Car"; }


Bicycle::Bicycle(float p, int speed, int yr, string col, string t)
    : Vehicle(p, speed, yr, col), type(t) {}

void Bicycle::showInfo() const {
    cout << "Bicycle - Price: " << price << ", Max Speed: " << maxSpeed
        << ", Year: " << year << ", Color: " << color
        << ", Type: " << type << "\n";
}

string Bicycle::getType() const { return "Bicycle"; }


Lorry::Lorry(float p, int speed, int yr, string col, float capacity)
    : Vehicle(p, speed, yr, col), loadCapacity(capacity) {}

void Lorry::showInfo() const {
    cout << "Lorry - Price: " << price << ", Max Speed: " << maxSpeed
        << ", Year: " << year << ", Color: " << color
        << ", Load Capacity: " << loadCapacity << " tons\n";
}

string Lorry::getType() const { return "Lorry"; }


Garage::~Garage() {
    for (auto v : vehicles)
        delete v;
}

void Garage::addVehicle(Vehicle* v) {
    vehicles.push_back(v);
}

void Garage::removeVehicle(int index) {
    if (index >= 0 && index < vehicles.size()) {
        delete vehicles[index];
        vehicles.erase(vehicles.begin() + index);
    }
}

void Garage::showAllVehicles() const {
    for (const auto& v : vehicles)
        v->showInfo();
}

Vehicle* Garage::searchByType(const string& type) const {
    for (const auto& v : vehicles) {
        if (v->getType() == type)
            return v;
    }
    return nullptr;
}

Vehicle* Garage::searchByIndex(int index) const {
    if (index >= 0 && index < vehicles.size())
        return vehicles[index];
    return nullptr;
}

Vehicle* Garage::searchByTypeAndSpeed(const string& type, int speed) const {
    for (const auto& v : vehicles) {
        if (v->getType() == type && v->getMaxSpeed() == speed)
            return v;
    }
    return nullptr;
}

void Garage::editVehicle(int index, float newPrice, string newColor) {
    if (index >= 0 && index < vehicles.size()) {
        vehicles[index]->setPrice(newPrice);
        vehicles[index]->setColor(newColor);
    }
}

void Garage::sortBySpeed() {
    sort(vehicles.begin(), vehicles.end(), [](Vehicle* v1, Vehicle* v2) {
        return v1->getMaxSpeed() > v2->getMaxSpeed();
        });
}
