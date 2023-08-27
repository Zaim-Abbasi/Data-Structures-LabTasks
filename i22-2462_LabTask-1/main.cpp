#include<iostream>
#include "hospital.h"
using namespace std;
int main() {
	string type, name;
	int medCharges, hospitalCharges;
	cout << "Enter Patient's name:";
	cin >> name;
	cout << "Enter the type of patient(in/out):";
	cin >> type;
	if (type == "in") {
		//inPatient
		int days;
		double dailyRate;
		
		
		cout << "Enter days spent in the hospital:";
		cin >> days;
		cout << "Enter daily Rate:";
		cin >> dailyRate;
		cout << "Enter charges for hospital medication:";
		cin >> hospitalCharges;
		cout << "Enter charges for hospital services:";
		cin >> medCharges;
		Patient p(name, type, days);
		Hospital h(p, medCharges, hospitalCharges, dailyRate);
		double total = h.Total(p,dailyRate, hospitalCharges, medCharges);
		cout << total << endl;
	}
	else if (type == "out") {
		//outPatient
		cout << "Enter charged for hospital services:";
		cin >> hospitalCharges;
		cout << "Enter charges for hospital medication:";
		cin >> medCharges;
		Patient p(name, type);
		Hospital h(p, medCharges, hospitalCharges);
		double total=h.Total(hospitalCharges, medCharges);
		cout << total << endl;
	}
	else {
		cout << "Invalid Type. Only Enter in or out" << endl;
	}
}