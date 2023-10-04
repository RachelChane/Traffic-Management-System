//pedestrian
#include <iostream>
#include <string>
using namespace std;
class Crosswalk {
private:
    bool signalActive;

public:
    Crosswalk() {
        signalActive = false;
    }

    void activateSignal() {
        signalActive = true;
        cout << "Crosswalk signal activated." <<endl;//you can walk
    }

    void deactivateSignal() {
        signalActive = false;
        cout << "Crosswalk signal deactivated." <<endl;//you can' walk yet
    }

  bool isSignalActive() const {
        return signalActive;
    }
    void emergencyStop() {
        if (signalActive) {
            cout << "Emergency stop! Signal deactivated due to emergency." << endl;
            signalActive = false;
        }
        else {
            cout << "No need for an emergency stop. Signal is already deactivated." << endl;
        }
    }
};

