#include <iostream>
#include <string>

class Student {
private:
    std::string studentId;
    std::string studentName;
    std::string studentProgram;

public:
    // Constructor: Initializes the Book object with provided values.
    Student(std::string sID, std::string sname, std::string sprogram)
    : studentId(sID), studentName(sname), studentProgram(sprogram) {}

    // Getter methods: Return the values of respective attributes.
    std::string getID() const { //get the Id number of the student
        return studentId;
    }

    std::string getName() const { //get the name of the student
        return studentName;
    }

    std::string getProgram() const { //get the student Program
        return studentProgram;
    }
};