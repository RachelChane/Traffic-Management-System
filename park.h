//Parking
#include <iostream>
using namespace std;
class ParkingLot {
private:
    int capacity;
    int occupiedSpaces;

public:
	
	
	
    ParkingLot(int lotCapacity) {
        capacity = lotCapacity;
        occupiedSpaces = 0;
    }

    bool isFull() const { // I don't want to modify the function
        return occupiedSpaces >= capacity;
    }
 
    void parkVehicle() {
        if (occupiedSpaces < capacity) {
            occupiedSpaces++;
            cout << "Vehicle parked. Occupied spaces: " << occupiedSpaces <<endl;
        } else {
            cout << "Parking lot is full. Cannot park vehicle." <<endl;
        }
    }

    void removeVehicle() {
        if (occupiedSpaces > 0) {
            occupiedSpaces--;
            cout << "Vehicle removed. Occupied spaces: " << occupiedSpaces << endl;
        } else {
            cout << "No vehicles in the parking lot." <<endl;
        }
    }
    double calculateParkingFee(int h, double f) {
        double feePerHour = f;
        int hoursParked=h;  // number of hours parked
        double totalFee = feePerHour * hoursParked;
        return totalFee;
    }
    int getAvailableSpaces() const {
        return capacity - occupiedSpaces;
    }
     int getCurrentCapacity() const {
        return occupiedSpaces;}
        
    
};

