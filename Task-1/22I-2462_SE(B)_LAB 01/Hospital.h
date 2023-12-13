#include "Patient.h"

class Hospital {
private:
    Patient patientOb;
    int medicationCharges;
    double dailyRate;
    int hospitalCharges;

public:
    Hospital(const Patient& patient, int medCharges, double dayRate, int hosCharges)
        : patientOb(patient), medicationCharges(medCharges), dailyRate(dayRate), hospitalCharges(hosCharges) {}

    double calculateCharges() {
        if (patientOb.getType() == "in-patient") {
            return dailyRate * patientOb.getNumDays() * hospitalCharges * medicationCharges;
        }
        else if (patientOb.getType() == "out-patient") {
            return hospitalCharges * medicationCharges;
        }
        else {
            cout << "Invalid patient type!" << endl;
            return 0;
        }
    }

    
    int getMedicationCharges() {
        return medicationCharges;
    }

    double getDailyRate() {
        return dailyRate;
    }

    int getHospitalCharges() {
        return hospitalCharges;
    }

    void setMedicationCharges(int charges) {
        medicationCharges = charges;
    }

    void setDailyRate(double rate) {
        dailyRate = rate;
    }

    void setHospitalCharges(int charges) {
        hospitalCharges = charges;
    }
};