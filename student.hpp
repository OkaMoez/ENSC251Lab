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

	string firstname() { return firstname_; }
	string lastname() { return lastname_; }
	float cgpa() { return cgpa_; }
	int researchscore() { return researchscore_; }

	void set_firstname(string firstname);
	void set_lastname(string lastname);
	void set_cgpa(float cgpa);
	void set_researchscore(int researchscore);
};

class DomesticStudent : public Student
{
private:
	string province_;

public:
    DomesticStudent();
	DomesticStudent(string firstname, string lastname, float cgpa,
		int researchscore, string province);

	string province() { return province_; }

	void set_province(string province);
};

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

	int reading() { return reading_; }
	int listening() { return listening_; }
	int speaking() { return speaking_; }
	int writing() { return writing_; }
	int total() { return total_; }

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

	string country() { return country_; }
    int reading() { return my_toelf_.reading(); }
    int listening() { return my_toelf_.listening(); }
    int speaking() { return my_toelf_.speaking(); }
    int writing() { return my_toelf_.writing(); }
    int total() { return my_toelf_.total(); }

	void set_country(string country);
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);
};
#endif
