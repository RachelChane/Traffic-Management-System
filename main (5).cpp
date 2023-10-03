#include <iostream>
#include "Road.h"
#include "Emergency.h"
#include "park.h"
#include "pedestrian.h"

using namespace std;

int main() {
	//int n;
	//int m;

    Crosswalk crosswalk;
    EmergencyService emergencyService;

    int systemChoice;

    while (true) {
        cout << "Enter a traffic system that you want to manage: " << endl;
        cout << "1. Parking" << endl;
        cout << "2. Emergency" << endl;
        cout << "3. Pedestrian" << endl;
        cout << "4. Road" << endl;
        cout << "5. Exit" << endl;

        cin >> systemChoice;

        switch (systemChoice) {
        case 1: {
                string userInput;
                string name, plateNo;
                double fee;
                int hour;
             int parkingCapacity;
             //int parkingLot;
              cout << "Enter the capacity of the parking lot: ";
                cin >> parkingCapacity;
                if(parkingCapacity==0){
                	break;
				}
				ParkingLot parkingLot(parkingCapacity);
				cout<<"----------------------------------------------------"<<endl;
                cout<<"Please Enter the service that you wanna use:"<<endl;
                cout << "Parked"<<endl;
				cout<<"Removed"<<endl;
				cout<<"Capacity"<<endl;
				cout<<"Available:";
                cin >> userInput;
                


                if (userInput == "Parked") {
                    while (!(parkingLot.isFull())) {
                        cout << "Enter name: ";
                        cin >> name;
                        cout << "Enter plate number: ";
                        cin >> plateNo;
                        cout<<"Name is:"<<name<<endl;
                        cout<<"Plate Number is:"<<plateNo<<endl;
                        parkingLot.parkVehicle();
                    }
                } else if (userInput == "Removed") {
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter plate number: ";
                    cin >> plateNo;
                    cout << "Enter parking fee: ";
                    cin >> fee;
                    cout << "Enter parking hour: ";
                    cin >> hour;
                    cout << "Name: " << name << endl;
                    cout << "Plate number: " << plateNo << endl;
                    cout << "Parking fee: " << fee << endl;
                    cout << "Parking hour: " << hour << endl;
                    cout << "Total fee: " << parkingLot.calculateParkingFee(hour, fee) <<" Birr"<< endl;
                    parkingLot.removeVehicle();
                } else if (userInput == "Capacity") {
                    cout << "Current car capacity: " << parkingLot.getCurrentCapacity()<< endl;    //are this working
                } else if (userInput == "Available") {
                    cout << "Available spaces: " << parkingLot.getAvailableSpaces() << endl;
                } else {
                    cout << "No space." << endl;
                }

                break;}

        case 2: {
                cout << "Enter your name: ";
                string name;
                cin.ignore(); //non interference of other line character on cin format
                getline(cin, name);

                cout << "Select emergency type (0 = FIRE Dept, 1 = MEDICAL Dept, 2 = CRIME Dept): ";
                int type;
                cin >> type;
                cin.ignore(); 

                cout << "Enter location: ";
                string location;

                getline(cin, location);

                emergencyService.sendEmergencySignal(static_cast<EmergencyType>(type), name, location);//convert type into emergency type
                if (type == FIRE) {
        emergencyService.dispatchEmergencyVehicle("Fire Truck", location);
    } else if (type == MEDICAL) {
        emergencyService.dispatchEmergencyVehicle("Ambulance", location);
    } else if (type == POLICE) {
        emergencyService.dispatchEmergencyVehicle("Police Vehicle", location);
    }
     
              emergencyService.clearRoad(location);

                break;
            }
case 3: {
    cout << "Activate the crosswalk signal? (y/n): ";
    char activateSignalInput;
    cin >> activateSignalInput;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (activateSignalInput == 'y' || activateSignalInput == 'Y') {
        crosswalk.activateSignal();
    } else {
        cout << "Signal is not active, wait for the signal to cross the road." << endl;
    }

    cout << "Perform an emergency stop? (y/n): ";
    char emergencyStopInput;
    cin >> emergencyStopInput;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (emergencyStopInput == 'y' || emergencyStopInput == 'Y') {
        if (crosswalk.isSignalActive()) {
            cout << "Emergency stop! Signal deactivated due to emergency." << endl;
            crosswalk.emergencyStop();
        }
        else {
            cout << "No need for an emergency stop. Signal is already deactivated." << endl;
        }
    }
    else {
        cout << "No emergency stop performed." << endl;
    }
}
    break;

            case 4: {

         int roadCapacity;
    cout << "Enter the capacity of the road: ";
    cin >> roadCapacity;

    Road road(roadCapacity);

    int choice;
    while (true) {
        cout << "---------------------------" << endl;
        cout << "Road Menu:" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Remove Vehicle" << endl;
        cout << "3. Check Road Congestion" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                road.addVehicle();
                break;
            case 2:
                road.removeVehicle();
                break;
            case 3:
                if (road.isCongested()) {
                    cout << "Road is congested." << endl;
                } else {
                    cout << "Road is not congested." << endl;
                }
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
                default:
                cout << "Invalid choice. Please try again." << endl;
                 break;
        }}}
        case 5:{
                cout << "Exiting the program..." << endl;
                return 0;
}
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
		}return 0;}

