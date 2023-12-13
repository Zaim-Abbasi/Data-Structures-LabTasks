#include <iostream>
#include "Hospital.h"
using namespace std;

int main() {
    string name, type;
    int numDays, medCharges, hosCharges;
    double dayRate;

    cout << "Enter patient's name: ";
    cin >> name;
    cout << "Enter patient type: ";
    cin >> type;

    if (type == "in-patient") {
        cout << "Enter number of days spent in the hospital: ";
        cin >> numDays;
        cout << "Enter daily rate: ";
        cin >> dayRate;
        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        cout << "Enter charges for hospital services: ";
        cin >> hosCharges;

        Patient patient(name, type, numDays);
        Hospital hospital(patient, medCharges, dayRate, hosCharges);
        double totalCharges = hospital.calculateCharges();

        cout << "Total charges: " << totalCharges << endl;
    }
    else if (type == "out-patient") {
        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        cout << "Enter charges for hospital services: ";
        cin >> hosCharges;

        Patient patient(name, type, 0);
        Hospital hospital(patient, medCharges, 0.0, hosCharges);
        double totalCharges = hospital.calculateCharges();

        cout << "Total charges: " << totalCharges << endl;
    }
    else {
        cout << "Invalid patient type!" << endl;
    }

    return 0;
}
