//student.cpp to implement your classes
#include <iostream>
#include "student.hpp"
#include "functions.hpp"
using namespace std;

// Student Constructor
Student::Student() { Student("empty", "empty", 0.0, 0); }
Student::Student(string firstname, string lastname, float cgpa,
    int researchscore)
{
    set_firstname(firstname);
    set_lastname(lastname);
    set_cgpa(cgpa);
    set_researchscore(researchscore);
}

// Student Member Functions
void Student::set_firstname(string firstname) { firstname_ = firstname; }
void Student::set_lastname(string lastname) { lastname_ = lastname; }
void Student::set_cgpa(float cgpa) { cgpa_ = cgpa; }
void Student::set_researchscore(int researchscore) { researchscore_ = researchscore; }
void Student::Print(ostream &output) const { output << " Untyped Student" << endl; }

// Overloading << for DomesticStudent
std::ostream &operator<<( ostream &output, const Student& student){
    student.Print(output);
    return output;
}

// DomesticStudent Constructor
DomesticStudent::DomesticStudent() { DomesticStudent("empty", "empty", 0.0, 0, "empty"); }
DomesticStudent::DomesticStudent(string firstname, string lastname,
    float cgpa, int researchscore, string province) :
    Student(firstname, lastname, cgpa, researchscore)
{
    set_province(province);
}

// DomesticStudent Member Function
void DomesticStudent::set_province(string province) { province_ = province; }
void DomesticStudent::Print(ostream &output) const {
    output << " " << firstname()
           << " " << lastname()
           << " from " << province()
           << " has a CGPA of " << cgpa()
           << ", and a research score of " << researchscore();
}

// Overloading << for DomesticStudent
std::ostream &operator<<( ostream &output, const DomesticStudent& student){
    student.Print(output);
    return output;
}

// ToelfScore Constructor
ToelfScore::ToelfScore(){ ToelfScore(0, 0, 0, 0); }
ToelfScore::ToelfScore(int reading, int listening, int speaking, int writing)
{
    set_reading(reading);
    set_listening(listening);
    set_speaking(speaking);
    set_writing(writing);
    update_total();
}

// ToelfScore Member Function
void ToelfScore::set_reading(int reading) { reading_ = reading; update_total(); }
void ToelfScore::set_listening(int listening) { listening_ = listening; update_total(); }
void ToelfScore::set_speaking(int speaking) { speaking_ = speaking; update_total(); }
void ToelfScore::set_writing(int writing) { writing_ = writing; update_total(); }
void ToelfScore::update_total() {
    total_ = reading_ + listening_ + speaking_ + writing_;
    update_requirements();
}
void ToelfScore::update_requirements(){ // Logic sets boolean for later sorting.  (See print_vector() in functions.cpp.)
    int min = 20;
    int min_total = 93;
    if ((reading() < min) || (listening() < min) || (speaking() < min) || (writing() < min) || (total() < min_total))
        meets_requirements_ = false;
    else
        meets_requirements_ = true;
}

// InternationalStudent Constructor
InternationalStudent::InternationalStudent() { InternationalStudent("empty", "empty", 0.0, 0, "empty", 0, 0, 0, 0); }
InternationalStudent::InternationalStudent(string firstname, string lastname,
    float cgpa,	int researchscore, string country, int reading, int listening,
    int speaking, int writing): Student(firstname, lastname, cgpa, researchscore)
{
    set_country(country);
    set_reading(reading);
    set_listening(listening);
    set_speaking(speaking);
    set_writing(writing);
}

// InternationalStudent Member Function
void InternationalStudent::set_country(string country) { country_ = country; }
void InternationalStudent::set_reading(int reading) { my_toelf_.set_reading(reading);}
void InternationalStudent::set_listening(int listening) { my_toelf_.set_speaking(listening);}
void InternationalStudent::set_speaking(int speaking) { my_toelf_.set_listening(speaking);}
void InternationalStudent::set_writing(int writing) { my_toelf_.set_writing(writing);}
void InternationalStudent::Print(ostream &output) const{
    output << " " << firstname()
           << " " << lastname()
           << " from " << country()
           << " has a CGPA of " << cgpa()
           << ", and a research score of " << researchscore()
           << " [TOELF] reading: " << reading()
           << ", listening: " << listening()
           << ", speaking: " << speaking()
           << ", writing: " << writing()
           << ", total: " << total();
}

// Overloading << for InternationalStudent
std::ostream &operator<<( ostream &output, const InternationalStudent& student) {
    student.Print(output);
    return output;
}
