//modified class from activity 3 last exercise
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string fname; //first name
    string lname; //last name
    string gender; //gender
    string emailAdd; //email address
    string cpNumber; //cell phone number

public:
    //constructors
    Person() : fname(""), lname(""), gender(""), emailAdd(""), cpNumber("") {}
    Person(string f, string l, string g, string e, string c) 
        : fname(f), lname(l), gender(g), emailAdd(e), cpNumber(c) {}

    //set methods
    void setFname(string f) { fname = f; }
    void setLname(string l) { lname = l; }
    void setGender(string g) { gender = g; }
    void setEmailAdd(string e) { emailAdd = e; }
    void setCpNumber(string c) { cpNumber = c; }

    //get methods
    string getFname() const { return fname; }
    string getLname() const { return lname; }
    string getGender() const { return gender; }
    string getEmailAdd() const { return emailAdd; }
    string getCpNumber() const { return cpNumber; }
};

#endif //PERSON_H
