#include "Vehicle.h"

using namespace std;

int main() {
    Garage garage;

    garage.addVehicle(new Car(15000, 220, 2018, "Red", 5));
    garage.addVehicle(new Bicycle(500, 30, 2021, "Blue", "Mountain"));
    garage.addVehicle(new Lorry(30000, 100, 2017, "White", 10));

    cout << "All vehicles:\n";
    garage.showAllVehicles();

    cout << "\nSearching for a Bicycle:\n";
    Vehicle* found = garage.searchByType("Bicycle");
    if (found) found->showInfo();

    cout << "\nEditing Car price and color:\n";
    garage.editVehicle(0, 16000, "Black");
    garage.showAllVehicles();

    cout << "\nSorting vehicles by speed:\n";
    garage.sortBySpeed();
    garage.showAllVehicles();

}
