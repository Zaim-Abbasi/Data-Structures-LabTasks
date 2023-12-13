#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
private:
    int serialNum;
    string RegDate, rollNum, name;
    float a1, a2, a3, a4, a5, s1, s2, proj1, proj2, final1, final2, mid1, mid2, gTotal;
    string Grade;

public:
    // constructors
    Student();

    // parameterized constructor with 15 parameters
    Student(int serialNum, string RegDate, string rollNum, string name, float a1, float a2, float a3, float a4, float a5, float s1, float s2, float proj1, float proj2, float mid1, float mid2, float final1, float final2, float gTotal, string Grade)
    {
        this->serialNum = serialNum;
        this->RegDate = RegDate;
        this->rollNum = rollNum;
        this->name = name;
        this->a1 = a1;
        this->a2 = a2;
        this->a3 = a3;
        this->a4 = a4;
        this->a5 = a5;
        this->s1 = s1;
        this->s2 = s2;
        this->proj1 = proj1;
        this->proj2 = proj2;
        this->mid1 = mid1;
        this->mid2 = mid2;
        this->final1 = final1;
        this->final2 = final2;
        this->gTotal = gTotal;
        this->Grade = Grade;
    }

    // getters
    int getSerialNum() { return serialNum; }
    string getRegDate() { return RegDate; }
    string getRollNum() { return rollNum; }
    string getName() { return name; }
    float getA1() { return a1; }
    float getA2() { return a2; }
    float getA3() { return a3; }
    float getA4() { return a4; }
    float getA5() { return a5; }
    float getS1() { return s1; }
    float getS2() { return s2; }
    float getProj1() { return proj1; }
    float getProj2() { return proj2; }
    float getMid1() { return mid1; }
    float getMid2() { return mid2; }
    float getFinal1() { return final1; }
    float getFinal2() { return final2; }
    float getGTotal() { return gTotal; }
    string getGrade() { return Grade; }

    // setters
    void setSerialNum(int serialNum) { this->serialNum = serialNum; }
    void setRegDate(string RegDate) { this->RegDate = RegDate; }
    void setRollNum(string rollNum) { this->rollNum = rollNum; }
    void setName(string name) { this->name = name; }
    void setA1(float a1) { this->a1 = a1; }
    void setA2(float a2) { this->a2 = a2; }
    void setA3(float a3) { this->a3 = a3; }
    void setA4(float a4) { this->a4 = a4; }
    void setA5(float a5) { this->a5 = a5; }
    void setS1(float s1) { this->s1 = s1; }
    void setS2(float s2) { this->s2 = s2; }
    void setProj1(float proj1) { this->proj1 = proj1; }
    void setProj2(float proj2) { this->proj2 = proj2; }
    void setMid1(float mid1) { this->mid1 = mid1; }
    void setMid2(float mid2) { this->mid2 = mid2; }
    void setFinal1(float final1) { this->final1 = final1; }
    void setFinal2(float final2) { this->final2 = final2; }
    void setGTotal(float gTotal) { this->gTotal = gTotal; }
    void setGrade(string Grade) { this->Grade = Grade; }
};
void Read()
{
    // reading from csv file
    ifstream fin;
    fin.open("data.csv", ios::in);
    if (!fin)
    {
        cout << "Error in opening file..!!";
        return;
    }
    string line, word;
    int count = 0;
    


}
