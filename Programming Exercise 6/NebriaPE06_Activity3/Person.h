#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string fname; //first name
    string lname; //last name
    string gender; //gender
public:
    //constructors
    Person() : fname(""), lname(""), gender("") {}
    Person(string f, string l, string g) : fname(f), lname(l), gender(g) {}

    //set methods
    void setFname(string f) { fname = f; }
    void setLname(string l) { lname = l; }
    void setGender(string g) { gender = g; }

    //get methods
    string getFname() const { return fname; }
    string getLname() const { return lname; }
    string getGender() const { return gender; }
};

#endif //PERSON_H