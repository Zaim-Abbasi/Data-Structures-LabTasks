#pragma once
#include "patient.h"
class Hospital {
private:
	Patient* p;
	int medCharges, hospitalCharges;
	double dailyRate;
public:
	Hospital() {
		
	}
	Hospital(Patient p, int medCharges, int hospitalCharges, double dailtRate) :p(&p), medCharges(medCharges), hospitalCharges(hospitalCharges), dailyRate(dailtRate)
	{

	}
	Hospital(Patient p, int medCharges, int hospitalCharges) :p(&p), medCharges(medCharges), hospitalCharges(hospitalCharges)
	{

	}
	double Total(Patient p,double dailyRate, int hospitalCharges, int medCharges) {
		return dailyRate * hospitalCharges * medCharges * p.GetDays();
	}
	double Total(int hospitalCharges, int medCharges)
	{
		return hospitalCharges * medCharges;
	}
};