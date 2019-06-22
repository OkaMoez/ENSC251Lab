// Headers contain empty declarations and trivial functions.
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include "constants.hpp"
#include "student.hpp"
using namespace std;

// User Input Function Prototypes
void start_sort(vector<DomesticStudent> &D_vector,
                vector<InternationalStudent> &I_vector);
template <class T> // This allows function to take either student derivative.
void get_sort_method(int student_type, vector<T> &loaded_vector);

// Sorting Function Protoypes
template <class T>
void sort_students(int sort_type, vector<T> &loaded_vector);
//void sort_country(vector<InternationalStudent> &loaded_vector);
//void sort_province(vector<DomesticStudent> &loaded_vector);

// Sorting Functor Prototype
struct CompareStudent{ // This is specifically to work with std::sort as a comparator.
    int type;
    int attribute;
    int compared_value;

    CompareStudent(int attribute);
    template <class T>
    bool operator()( const T &student1, const T &student2);
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
int compare_location(const DomesticStudent& student1, const DomesticStudent& student2);
int compare_location(const InternationalStudent& student1, const InternationalStudent& student2);

// Output Function Prototypes (overloaded)
void print_vector(int selection, vector<DomesticStudent> &loaded_vector);
void print_vector(int selection, vector<InternationalStudent> &loaded_vector);

#endif // FUNCTIONS_HPP
