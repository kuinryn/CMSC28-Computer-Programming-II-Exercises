#include <iostream>
#include "Employees.h"

using namespace std;

int main() {
    //display initial message
    cout << "This program will call all the methods that I have implemented for Class Employees and all the methods that it inherited from Class Person.\n";
    cout << "Programmed by: Quennie A. Nebria\n\n";

    //variables for user input
    string fname, lname, gender, email, cpNumber, empNum, position, office;
    double salary;

    //user input for employee details
    cout << "Enter Employee First Name: ";
    getline(cin, fname);
    cout << "Enter Employee Last Name: ";
    getline(cin, lname);
    cout << "Enter Employee Gender: ";
    getline(cin, gender);
    cout << "Enter Employee Email Address: ";
    getline(cin, email);
    cout << "Enter Employee Cellphone Number: ";
    getline(cin, cpNumber);
    cout << "Enter Employee Number: ";
    getline(cin, empNum);
    cout << "Enter Position: ";
    getline(cin, position);
    cout << "Enter Office/Unit: ";
    getline(cin, office);
    cout << "Enter Salary: ";
    cin >> salary;

    //create the employee object from user input
    Employees employee(fname, lname, gender, email, cpNumber, empNum, position, office, salary);

    //display the input employee details
    cout << "\n---------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "Employee Name: " << employee.getFname() << " " << employee.getLname() << endl;
    cout << "Employee Gender: " << employee.getGender() << endl;
    cout << "Email Address: " << employee.getEmailAdd() << endl;
    cout << "Cellphone Number: " << employee.getCpNumber() << endl;
    cout << "Employee Number: " << employee.getEmpNum() << endl;
    cout << "Position: " << employee.getPosition() << endl;
    cout << "Office/Unit: " << employee.getOffice() << endl;
    cout << "Salary: " << employee.getSalary() << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "Hi, " << employee.getFname() << " " << employee.getLname() << "! Welcome to Mugna. We are pleased to inform you that you are appointed as " << employee.getPosition() << " in the " << employee.getOffice() << " unit. Your Employee number is " << employee.getEmpNum() << ". Your salary is $" << employee.getSalary() << ".\n";

    return 0;
}
