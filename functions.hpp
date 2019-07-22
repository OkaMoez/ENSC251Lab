// Headers contain empty declarations and trivial functions.
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "studentlists.hpp"
using namespace std;

// User Input Function Prototypes
void StartMenu(StudentList &D_list, StudentList &I_list);
void ListMenu(int kDomestic, StudentList &loaded_list);
StudentList MergeList(StudentList &list1, StudentList &list2);
void SearchType(int student_type, StudentList &loaded_list);
void Search(int search_type, StudentList &loaded_list);
void MakeNewStudent(int student_type,StudentList &loaded_list);
void SearchAndDestroy(StudentList &loaded_list);
string GetString(int target_type);
float GetCGPA();
int GetIntScore(int traget_type);
string CleanPNounInput(string dirty_string);
string CleanProvinceInput(string dirty_string);
string CleanCharacter(string string_in, char char_in);

// Sorting Functor Prototype
struct CompareStudent{ // This is specifically to work with std::sort as a comparator.
    int type;
    int attribute;

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

// Std::Replacement Function Prototypes
bool StringContains(string string_in, char char_in);
bool StringArrayContains(const string array_in[], string string_in);

#endif // FUNCTIONS_HPP
