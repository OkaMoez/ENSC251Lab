// Headers contain empty declarations and trivial functions.
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "constants.hpp"

class Student
{
private:
    int student_type_; // 0 for untyped, kDomestic, or kInternational
	string firstname_;
	string lastname_;
	float cgpa_;
    int researchscore_;

public:
    // Contructors & Destructors
    Student();
    Student(int student_type_, string firstname, string lastname, float cgpa, int researchscore);
    virtual ~Student() {}


    // Getters
    int student_type() const { return student_type_; }
    string firstname() const { return firstname_; }
    string lastname() const { return lastname_; }
    float cgpa() const { return cgpa_; }
    int researchscore() const { return researchscore_; }
    virtual string location() const { return "No Location."; }
    virtual bool check_requirements() const  { return true; }

    virtual void Print(ostream &output) const;
        // Pre: An open ostream
        // Post: Student details added to ostream; used to overload <<


    // Setters
    void set_student_type(int student_type);
	void set_firstname(string firstname);
	void set_lastname(string lastname);
	void set_cgpa(float cgpa);
    void set_researchscore(int researchscore);


    // Friend Functions
    template <class T>
    friend int compare_firstname(const T& student1, const T& student2);
        // Pre: Two students
        // Post: Returned -1 if student1 sorts higher alphabetically, 0 if equal, 1 if lower

    template <class T>
    friend int compare_lastname(const T& student1, const T& student2);
        // Pre: Two students
        // Post: Returned -1 if student1 sorts higher alphabetically, 0 if equal, 1 if lower

    template <class T>
    friend int compare_cgpa(const T& student1, const T& student2);
        // Pre: Two students
        // Post: Returned 1 if student1 is greater, 0 if equal, 1 if less than student2

    template <class T>
    friend int compare_researchscore(const T& student1, const T& student2);
        // Pre: Two students
        // Post: Returned 1 if student1 is greater, 0 if equal, 1 if less than student2

    // << Operator Overload
    friend ostream& operator<<( ostream& output, const Student& student);
        // Pre: A student object
        // Post: Passed formatted student info for cout printing
};



class DomesticStudent : public Student
{
private:
    string province_;

public:
    // Constructors
    DomesticStudent();
	DomesticStudent(string firstname, string lastname, float cgpa,
        int researchscore, string province);


    // Getters
    string province() const { return province_; }
    virtual string location() const override {return province_;}
    virtual bool check_requirements() const override { return true; }

    virtual void Print(ostream &output) const override;
        // Pre: An open ostream
        // Post: Student details added to ostream; used to overload <<


    // Setters
    void set_province(string province);


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
    void update_total();

public:
    // Constructors
    ToelfScore();
    ToelfScore(int reading, int listening, int speaking, int writing);


    // Getters
    int reading() const { return reading_; }
    int listening() const { return listening_; }
    int speaking() const { return speaking_; }
    int writing() const { return writing_; }
    int total() const { return total_; }
    bool check_requirements() const { return meets_requirements_; }


    // Setters
	void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
	void set_writing(int writing);

    void update_requirements();
        // Pre: Filled toelf scores
        // Post: Updated bool to reflect if toelf scores pass for sorting (ie total > 80)
};



class InternationalStudent : public Student
{
private:
	string country_;
    ToelfScore my_toelf_;

public:
    // Constructors
    InternationalStudent();
    InternationalStudent(string firstname, string lastname, float cgpa,
        int researchscore, string country, int reading, int listening,
        int speaking, int writing);


    // Getters
    virtual string location() const override {return country_;}
    string country() const { return country_; }
    int reading() const { return my_toelf_.reading(); }
    int listening() const { return my_toelf_.listening(); }
    int speaking() const { return my_toelf_.speaking(); }
    int writing() const { return my_toelf_.writing(); }
    int total() const { return my_toelf_.total(); }
    virtual bool check_requirements() const override { return my_toelf_.check_requirements(); }  // Added for sorting.

    virtual void Print(ostream &output) const override;
        // Pre: An open ostream
        // Post: Student details added to ostream; used to overload <<


    // Setters
    void set_country(string country);
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);


    // << Operator Overload
    friend ostream& operator<<( ostream& output, const InternationalStudent& student);
};

#endif //STUDENT_HPP
