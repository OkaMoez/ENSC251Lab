// Headers contain empty declarations and trivial functions.
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "studentlists.hpp"
using namespace std;

// User Input Function Prototypes
void StartMenu(StudentList &D_list, StudentList &I_list);
    // Pre: Populated student lists
    // Post: Program has been accessed

void ListMenu(int kDomestic, StudentList &loaded_list);
    // Pre: One specific student list
    // Post: User was able to add, search, delete, and/or print from/to student lists

StudentList MergeList(StudentList &list1, StudentList &list2);
    // Pre: Two separate lists
    // Post: One new unified list

void SearchType(int student_type, StudentList &loaded_list);
    // Pre: A student list and specified type (ie Domestic)
    // Post: Call Search() which found and printed target students

void Search(int search_type, StudentList &loaded_list);
    // Pre: A student list and specified type (ie Domestic) and call from SearchType()
    // Post: Printed target students if found

void MakeNewStudent(int student_type,StudentList &loaded_list);
    // Pre: A student list and specified type (ie Domestic)
    // Post: Inserted new student into list

void SearchAndDestroy(StudentList &loaded_list);
    // Pre: A student list
    // Post: Deleted targets from list who matched input

string GetString(int target_type);
    // Pre: Desired string type (ie firstname)
    // Post: Returned a correctly formated string of the specified type

float GetCGPA();
    // Pre: None
    // Post: Returned a valid CGPA (ie float, 0 <= x <= 4.33)

int GetIntScore(int traget_type);
    // Pre: None
    // Post: Returned a valid research score (ie int, 0 <= x <= 100)

string CleanPNounInput(string dirty_string);
    // Pre: A string (assumed raw, ie " jo Hn ")
    // Post: Returned a string with no whitespace and a leading uppercase (ie "John")

string CleanProvinceInput(string dirty_string);
    // Pre: A string (assumed raw, ie "bC")
    // Post: Returned an uppercase string

string CleanCharacter(string string_in, char char_in);
    // Pre: A string (ie "happy") and a specific character (ie 'p')
    // Post: Returned the same string without instances of the specified character (ie "hay")



// Sorting Functor Prototype
struct CompareStudent{ // Allows student comparison of a specified attribute.
    int type;
    int attribute;

    CompareStudent(int attribute);
    bool operator()( const Student &student1, const Student &student2);
    // Pre: Instance of CompareStudent with selected attribute (ie CompareStudent(kFirstname))
    // Post: Returned true if student1 sorts higher, false if student2 sorts higher
};



// Friend Function Prototypes
// ***THESE ONLY EXIST FOR MARKS, OTHERWISE USE CompareStudent()***
template <class T>
int compare_firstname(const T& student1, const T& student2);
    // Pre: Two students
    // Post: Returned -1 if student1 sorts higher alphabetically, 0 if equal, 1 if lower

template <class T>
int compare_lastname(const T& student1, const T& student2);
    // Pre: Two students
    // Post: Returned -1 if student1 sorts higher alphabetically, 0 if equal, 1 if lower

template <class T>
int compare_cgpa(const T& student1, const T& student2);
    // Pre: Two students
    // Post: Returned 1 if student1 is greater, 0 if equal, 1 if less than student2

template <class T>
int compare_researchscore(const T& student1, const T& student2);
    // Pre: Two students
    // Post: Returned 1 if student1 is greater, 0 if equal, 1 if less than student2

template <class T>
int compare_location(const T& student1, const T& student2);
    // Pre: Two students
    // Post: Returned -1 if student1 sorts higher alphabetically, 0 if equal, 1 if lower
    // Post cont: Overrides to -1 if student1 is domestic and student2 is international



// Std::Replacement Function Prototypes
bool StringContains(string string_in, char char_in);
    // Pre: A string and a specified character
    // Post: Returned true if target character is found, false if not; replacing std::find()

bool StringArrayContains(const string array_in[], string string_in);
    // Pre: A string array and a specified string
    // Post: Returned true if target string is found, false if not; replacing std::find()

#endif // FUNCTIONS_HPP
