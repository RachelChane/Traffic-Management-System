#include <iostream>
using namespace std;

class Road {
private:
    int capacity;
    int numVehiclesAdded;
    int numVehiclesRemoved;

public:
    Road(int roadCapacity) {
        capacity = roadCapacity;
        numVehiclesAdded = 0;
        numVehiclesRemoved = 0;
    }

    void addVehicle() {
        if (numVehiclesAdded < capacity) {
            numVehiclesAdded++;
            cout << "Vehicle added. Current number of vehicles: " << numVehiclesAdded << endl;
        } else {
            cout << "Cannot add vehicle. Road is congested." << endl;
        }
    }

    void removeVehicle() {
        if (numVehiclesAdded > numVehiclesRemoved) {
            numVehiclesRemoved++;
            cout << "Vehicle removed. Current number of vehicles: " << numVehiclesAdded - numVehiclesRemoved << endl;
        } else {
            cout << "No vehicles on the road." << endl;
        }
    }

    bool isCongested() const {
        return numVehiclesAdded == capacity;
    }
};

