#include <string>
using namespace std;

class Grades { //define Grades 
private:
    string subname; //variable to hold subject name
    float grd; //variable to hold grade

public:
    Grades() {}

    void setsub(const string &newsub) {
        subname = newsub;
    }

    void setgrd(float newgrd) {
        grd = newgrd;
    }

    //returns the grade result
    string result() const {
        if (grd < 0 || grd > 100) {
            return "Invalid score."; //return error message if grade is invalid
        } else {
            return grd >= 60 ? "Passed." : "Failed."; //return pass/fail based on grade
        }
    }

    //gets the grade
    float getgrd() const {
        return grd;
    }
 
    //gets the subject name
    string getsub() const {
        return subname;
    }
};

