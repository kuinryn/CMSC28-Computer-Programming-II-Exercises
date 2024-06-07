#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Person.h" //enable inheriting from person class

class Student : public Person {
private:
    string studentNum;
    string Course;
    string Department;
    string College;

public:
    //constructor
    Student(string fname, string lname, string gender, string email, string cpNumber, string studentNum, string course, string department, string college)
        : Person(fname, lname, gender, email, cpNumber), studentNum(studentNum), Course(course), Department(department), College(college) {}

    //getters and setters
    string getStudentNum() const { return studentNum; }
    void setStudentNum(const string& studentNum) { this->studentNum = studentNum; }

    string getCourse() const { return Course; }
    void setCourse(const string& course) { Course = course; }

    string getDepartment() const { return Department; }
    void setDepartment(const string& department) { Department = department; }

    string getCollege() const { return College; }
    void setCollege(const string& college) { College = college; }


};

#endif
