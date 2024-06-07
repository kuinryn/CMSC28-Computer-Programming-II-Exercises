#include <iostream>
using namespace std;

class Person { //define Person
private:
    int a; //variable to hold age
    char g; //variable to hold gender

public:
    Person() : a(0), g('M') {} //initializing age to 0 and gender to M
    Person(int upAge) : a(upAge), g('M') {}
    Person(int upAge, char upGender) : a(upAge), g(upGender) {}

    //sets age 
    void set_a(int upAge) {
        if (upAge >= 0) {
            a = upAge;
        } else {
            cout << "Invalid age!!!" << endl;
        }
    }

    //gets age
    int get_a() const {
        return a;
    }

    //sets gender
    void set_g(char upGender) {
        if (upGender == 'M' || upGender == 'F') {
            g = upGender;
        } else {
            cout << "Invalid gender!!!" << endl;
        }
    }

    //gets gender
    char get_g() const {
        return g;
    }

    //display age and gender
    void view() const {
        cout << "Person age is = " << get_a() << endl;
        cout << "Person gender is = " << get_g() << endl;
    }

    //another way to display age and gender
    void view(int upAge) const {
        cout << "Person age is = " << upAge << endl;
        cout << "Person gender is = " << get_g() << endl;
    }

    //another way to display age and gender
    void view(int upAge, char upGender) const {
        cout << "Person age is = " << upAge << endl;
        cout << "Person gender is = " << upGender << endl; 
    }
};
