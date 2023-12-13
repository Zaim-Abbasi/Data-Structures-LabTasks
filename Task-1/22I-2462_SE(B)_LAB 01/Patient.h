#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    string Name;
    string type;
    int NumDays; 

public:
    Patient(string name, string patType, int numDays) : Name(name), type(patType), NumDays(numDays) {}

    string getName() const {
        return Name;
    }

    string getType() const {
        return type;
    }

    int getNumDays() const {
        return NumDays;
    }

    void setName(const string& name) {
        Name = name;
    }

    void setType(const string& patType) {
        type = patType;
    }

    void setNumDays(int numDays) {
        NumDays = numDays;
    }
};