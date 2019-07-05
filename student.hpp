// Headers contain empty declarations and trivial functions.
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "constants.hpp"

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
    virtual ~Student() {}

    string firstname() const { return firstname_; }
    string lastname() const { return lastname_; }
    float cgpa() const { return cgpa_; }
    int researchscore() const { return researchscore_; }
    virtual string location() const { return "No Location."; }

	void set_firstname(string firstname);
	void set_lastname(string lastname);
	void set_cgpa(float cgpa);
    void set_researchscore(int researchscore);
    virtual void Print(ostream &output) const;

    // Friend Functions
    template <class T>
    friend int compare_firstname(const T& student1, const T& student2);
    template <class T>
    friend int compare_lastname(const T& student1, const T& student2);
    template <class T>
    friend int compare_cgpa(const T& student1, const T& student2);
    template <class T>
    friend int compare_researchscore(const T& student1, const T& student2);
    friend ostream& operator<<( ostream& output, const Student& student);
};

class DomesticStudent : public Student
{
private:
    string province_;

public:
    DomesticStudent();
	DomesticStudent(string firstname, string lastname, float cgpa,
        int researchscore, string province);

    virtual string location() const override {return province_;}

    string province() const { return province_; }

    void set_province(string province);
    virtual void Print(ostream &output) const override;

    // << Operator Overload
    friend ostream& operator<<( ostream& output, const DomesticStudent& student);
};

class ToelfScore
{
private:
	int reading_;
	int listening_;
	int speaking_;
	int writing_;
	int total_;
    bool meets_requirements_;  // Added for sorting.

public:
    ToelfScore();
    ToelfScore(int reading, int listening, int speaking, int writing);

    int reading() const { return reading_; }
    int listening() const { return listening_; }
    int speaking() const { return speaking_; }
    int writing() const { return writing_; }
    int total() const { return total_; }
    bool check_requirements() const { return meets_requirements_; }  // Added for sorting.

	void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
	void set_writing(int writing);
    void update_requirements();  // Added for sorting.
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

    virtual string location() const override {return country_;}
    string country() const { return country_; }
    int reading() const { return my_toelf_.reading(); }
    int listening() const { return my_toelf_.listening(); }
    int speaking() const { return my_toelf_.speaking(); }
    int writing() const { return my_toelf_.writing(); }
    int total() const { return my_toelf_.total(); }
    bool check_requirements() const { return my_toelf_.check_requirements(); }  // Added for sorting.

    void set_country(string country);
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);
    virtual void Print(ostream &output) const override;

    // << Operator Overload
    friend ostream& operator<<( ostream& output, const InternationalStudent& student);
};
#endif //STUDENT_HPP
