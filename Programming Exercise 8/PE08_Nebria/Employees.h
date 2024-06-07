#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <string>
#include "Person.h" //enable inheriting from person class

class Employees : public Person {
private:
    string empNum; //employee number
    string position; //position of employee
    string office; //office/unit
    double salary; //salary of employee

public:
    //constructors
    Employees() : Person(), empNum(""), position(""), office(""), salary(0.0) {}
    Employees(string f, string l, string g, string e, string c, string eNum, string pos, string unit, double sal)
        : Person(f, l, g, e, c), empNum(eNum), position(pos), office(unit), salary(sal) {}

    //setters and getters
    void setEmpNum(const std::string& eNum) { empNum = eNum; }
    string getEmpNum() const { return empNum; }

    void setPosition(const std::string& pos) { position = pos; }
    string getPosition() const { return position; }

    void setOffice(const std::string& unit) { office = unit; }
    string getOffice() const { return office; }

    void setSalary(double sal) { salary = sal; }
    double getSalary() const { return salary; }
};

#endif
