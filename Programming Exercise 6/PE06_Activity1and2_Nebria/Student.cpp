#include <iostream>
using namespace std;

class Student {
private: 
    string studentId;
    string studentName;
    string studentProgram;

public:
    Student(string sId, string sname, string sprogram){
        studentId = sId;
        studentName = sname;
        studentProgram = sprogram;
    }

    void display() {
        cout << "Student Number: " << studentId << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Program: " << studentProgram << endl;
    }
};

int main(){
    Student std1("2023-05107", "Quennie Nebria", "BSCS");
    std1.display();

    return 0;
}