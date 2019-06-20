//header file student.hpp to declare your classes
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string> //you will have to use string in C++
using namespace std; //use namespace std

class Student
{
private:
	string firstname_;
	string lastname_;
	float cgpa_;
	int researchscore_;

public:
    Student();
	Student(string firstname, string lastname, float cgpa, int researchscore);

    string firstname() const { return firstname_; }
    string lastname() const { return lastname_; }
    float cgpa() const { return cgpa_; }
    int researchscore() const { return researchscore_; }

	void set_firstname(string firstname);
	void set_lastname(string lastname);
	void set_cgpa(float cgpa);
	void set_researchscore(int researchscore);

    friend int compare_firstname();
    friend int compare_lastname();
    friend int compare_cgpa();
    friend int compare_researchscore();
};

class DomesticStudent : public Student
{
private:
	string province_;

public:
    DomesticStudent();
	DomesticStudent(string firstname, string lastname, float cgpa,
		int researchscore, string province);

    string province() const { return province_; }

	void set_province(string province);

    friend ostream& operator<<( ostream& output, const DomesticStudent& student);
};

std::ostream& operator<<( ostream& output, const DomesticStudent& student);

class ToelfScore
{
private:
	int reading_;
	int listening_;
	int speaking_;
	int writing_;
	int total_;

public:
    ToelfScore();
    ToelfScore(int reading, int listening, int speaking, int writing);

    int reading() const { return reading_; }
    int listening() const { return listening_; }
    int speaking() const { return speaking_; }
    int writing() const { return writing_; }
    int total() const { return total_; }

	void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
	void set_writing(int writing);
	void update_total();
};

class InternationalStudent : public Student
{
private:
	string country_;
    ToelfScore my_toelf_;

public:
    InternationalStudent();
    InternationalStudent(string firstname, string lastname, float cgpa,
        int researchscore, string country, int reading, int listening,
        int speaking, int writing);

	string country() const { return country_; }
    int reading() const { return my_toelf_.reading(); }
    int listening() const { return my_toelf_.listening(); }
    int speaking() const { return my_toelf_.speaking(); }
    int writing() const { return my_toelf_.writing(); }
    int total() const { return my_toelf_.total(); }

    void set_country(string country);
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);

    friend ostream& operator<<( ostream& output, const InternationalStudent& student);
};

std::ostream& operator<<( ostream& output, const InternationalStudent& student);

#endif
