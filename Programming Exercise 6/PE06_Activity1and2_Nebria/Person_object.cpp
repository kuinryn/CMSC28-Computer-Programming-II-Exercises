#include <iostream>
#include <string>
#include "Person.h" //include the Person class header file
#include "Grade.h" //include the Grade class header file
using namespace std;

int main() {
    int age; //variable to hold age
    char gender; //variable to hold gender
    string subject; //variable to hold subject
    float grade; //variable to hold grade

    //create the first Person object (p) using the default constructor
    cout << "Creating the 1st Person object (p) using the 1st Constructor" << endl;
    Person p;

    //input and set the age
    cout << "\nInput age: ";
    cin >> age;
    p.set_a(age);

    //input and set the gender
    cout << "Input gender (M/F): ";
    cin >> gender;
    p.set_g(gender);

    //output the age and gender
    cout << "Age = " << p.get_a() << endl;
    cout << "Gender = " << p.get_g() << endl;

    //Demonstrate method overloading by calling different versions of the view method
    cout << "\nThis is an example of method overloading: \n";
    cout << "Using view 1: \n";
    p.view();
    cout << "\nUsing view 2: \n";
    p.view(age);
    cout << "\nUsing view 3: \n";
    p.view(age, gender);

    cout << "\n==========================USING NEW HEADER FILE==========================\n";
    cout << "Creating the 1st Grade object" << endl;
    Grades x;

    //input and set the subject
    cout << "Input subject: ";
    cin >> subject;
    x.setsub(subject);

    //input and set the grade
    cout << "Input grade: ";
    cin >> grade;
    x.setgrd(grade);

    //output the subject and grade, and the grade status
    cout << "\nSubject = " << x.getsub() << endl;
    cout << "Grade = " << x.getgrd() << endl;
    cout << "Person has a grade of " << x.getgrd() << " for his/her subject " << x.getsub() << "." << endl;
    cout << "Grade Status: " << x.result() << endl;

    return 0;
}
