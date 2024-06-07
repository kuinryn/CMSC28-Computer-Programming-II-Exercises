#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    //display initial message
    cout << "This program will call all the methods that I have implemented for Class Student and all the methods that it inherited from Class Person.\n";
    cout << "Programmed by: Quennie A. Nebria\n\n";

    //variables for user input
    string fname, lname, gender, email, cpNumber, studentNum, course, department, college;

    //user input for student details
    cout << "Enter Student First Name: ";
    getline(cin, fname);
    cout << "Enter Student Last Name: ";
    getline(cin, lname);
    cout << "Enter Student Gender: ";
    getline(cin, gender);
    cout << "Enter Student Email Address: ";
    getline(cin, email);
    cout << "Enter Student Cellphone Number: ";
    getline(cin, cpNumber);
    cout << "Enter Student Number: ";
    getline(cin, studentNum);
    cout << "Enter Course: ";
    getline(cin, course);
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter College: ";
    getline(cin, college);

    //create the student object with user input
    Student student(fname, lname, gender, email, cpNumber, studentNum, course, department, college);

    //display the input student details
    cout << "\n---------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "Student Name: " << student.getFname() << " " << student.getLname() << endl;
    cout << "Student Gender: " << student.getGender() << endl;
    cout << "Email Address: " << student.getEmailAdd() << endl;
    cout << "Cellphone Number: " << student.getCpNumber() << endl;
    cout << "Student Number: " << student.getStudentNum() << endl;
    cout << "Course: " << student.getCourse() << endl;
    cout << "Department: " << student.getDepartment() << endl;
    cout << "College: " << student.getCollege() << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "Hi, " << student.getFname() << " " << student.getLname() << "! Welcome to UP Mindanao and congratulations! We are pleased to inform you that you are admitted in the " << student.getCourse() << " program under the " << student.getDepartment() << ", " << student.getCollege() << ". Your Student number is " << student.getStudentNum() << ".\n";

    return 0;
}
