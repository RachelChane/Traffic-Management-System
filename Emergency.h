#include <iostream>
#include <cstdlib>   
//#include <ctime>
//#include <cstddef>
#include <cstring>
using namespace std;

enum EmergencyType {
    FIRE,
    MEDICAL,
    POLICE
};

class EmergencyService {
public:
    void sendEmergencySignal(EmergencyType emergencyType, const string& name, const string& location) const;
   // void receiveEmergencyCall(const string& phoneNumber) const;
    void dispatchEmergencyVehicle(const string& vehicleType, const string& location) const;
    void clearRoad(const string& location) const;
};

void EmergencyService::sendEmergencySignal(EmergencyType emergencyType, const string& name, const string& location) const {//scope resolution to acess functions
    string emergencyText;
  if (emergencyType == FIRE) {
        emergencyText = "Fire Dept";
    } else if (emergencyType == MEDICAL) {
        emergencyText = "Medical Dept";
    } else if (emergencyType == POLICE) {
        emergencyText = "Police Dept";
    } else {
        emergencyText = "Unknown";
    }

    cout << "Name: " << name << endl;
    cout << "Emergency signal sent: " << emergencyText << " at " << location << endl;
}

//void EmergencyService::receiveEmergencyCall(const string& phoneNumber) const {
//    cout << "Received emergency call from: " << phoneNumber << endl;
//    cout << "Please stay calm. Help is on the way." << endl;
//}

void EmergencyService::dispatchEmergencyVehicle(const string& vehicleType, const string& location) const {
    cout << "Dispatching " << vehicleType << " at " << location <<" station "<< endl;
}

void EmergencyService::clearRoad(const string& location) const {
    cout << "Clearing the road at " << location << endl;
    // Implement the functionality to clear the road here
    cout << "Road cleared at " << location << endl;
}

//string generateRandomPhoneNumber() {
//	long long int* time_t = nullptr; 
//    string phoneNumber = "+";
//    srand(time(nullptr); // Seed the random number generator with the current time
//    for (int i = 0; i < 10; ++i) {
//        phoneNumber += to_string(rand() % 10); // Generate a random digit (0-9) and append it to the phone number
//    }
 //   return phoneNumber;


