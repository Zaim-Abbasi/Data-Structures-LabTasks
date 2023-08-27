#pragma once
using namespace std;
class Patient {
private:
	string name, type;
	int days;
public:
	Patient(){}
	Patient(string name, string type) :name(name), type(type) {

	}
	Patient(string name, string type, int days) :name(name), type(type), days(days)
	{

	}
	int GetDays() {
		return days;
	}
	
};
