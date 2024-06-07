#include <iostream>
#include "Student.h" //Including the header file for the Student class

int main() {
    Student student("2023-05107", "Quennie Nebria", "BSCS"); //Creating a Student object with the specified Id number, name, and program

    std::cout << "Student Number: " << student.getID() << std::endl; //Printing the student number
    std::cout << "Student Name: " << student.getName() << std::endl; //Printing the student name
    std::cout << "Program: " << student.getProgram() << std::endl; //Printing the student's program
    

    std::cout << "--------------------------------------------------------" << std::endl;

}