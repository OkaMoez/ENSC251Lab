// Headers contain empty declarations and trivial functions.
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "studentlists.hpp"
using namespace std;

// User Input Function Prototypes
void StartMenu(StudentList &D_list/*, IStudentList &I_List*/);
void ListMenu(int kDomestic, StudentList &loaded_list);
void SearchType(int student_type, StudentList &loaded_list);
void Search(int search_type, StudentList &loaded_list);
void MakeNewStudent(int student_type,StudentList &loaded_list);
void SearchAndDestroy(StudentList &loaded_list);
string GetTarget(string target_type);
float GetTarget(float target_type);
int GetTarget(int target_type);
string CleanNameInput(string dirty_string);

// Sorting Functor Prototype
struct CompareStudent{ // This is specifically to work with std::sort as a comparator.
    int type;
    int attribute;
    int compared_value;

    CompareStudent(int attribute);
    //template <class T>
    bool operator()( const Student &student1, const Student &student2);
};

// Friend Function Prototypes
template <class T>
int compare_firstname(const T& student1, const T& student2);
template <class T>
int compare_lastname(const T& student1, const T& student2);
template <class T>
int compare_cgpa(const T& student1, const T& student2);
template <class T>
int compare_researchscore(const T& student1, const T& student2);
template <class T>
int compare_location(const T& student1, const T& student2);

#endif // FUNCTIONS_HPP
