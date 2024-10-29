#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    float price;
    int maxSpeed;
    int year;
    string color;

public:
    Vehicle(float p, int speed, int yr, string col);
    virtual void showInfo() const = 0;

    float getPrice() const;
    int getMaxSpeed() const;
    int getYear() const;
    string getColor() const;

    void setPrice(float p);
    void setColor(string col);
    virtual string getType() const = 0;
};

class Car : public Vehicle {
private:
    int seatCount;

public:
    Car(float p, int speed, int yr, string col, int seats);
    void showInfo() const override;
    string getType() const override;
};

class Bicycle : public Vehicle {
private:
    string type;

public:
    Bicycle(float p, int speed, int yr, string col, string t);
    void showInfo() const override;
    string getType() const override;
};

class Lorry : public Vehicle {
private:
    float loadCapacity;

public:
    Lorry(float p, int speed, int yr, string col, float capacity);
    void showInfo() const override;
    string getType() const override;
};

class Garage {
private:
    vector<Vehicle*> vehicles;

public:
    ~Garage();
    void addVehicle(Vehicle* v);
    void removeVehicle(int index);
    void showAllVehicles() const;
    Vehicle* searchByType(const string& type) const;
    Vehicle* searchByIndex(int index) const;
    Vehicle* searchByTypeAndSpeed(const string& type, int speed) const;
    void editVehicle(int index, float newPrice, string newColor);
    void sortBySpeed();
};


