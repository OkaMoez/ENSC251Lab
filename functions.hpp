#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <string>
#include <vector>
#include "student.hpp"
using namespace std;

// user input function prototypes
void start_sort(vector<DomesticStudent> &D_vector,
                vector<InternationalStudent> &I_vector);
template <class T> // allow function to take either student type
void get_sort_method(int type, vector<T> &loaded_vector);

// sorting function protoypes
template <class T>
void sort_firstname(vector<T> &loaded_vector);
template <class T>
void sort_lastname(vector<T> &loaded_vector);
template <class T>
void sort_cgpa(vector<T> &loaded_vector);
template <class T>
void sort_researchscore(vector<T> &loaded_vector);
template <class T>
void sort_overall(vector<T> &loaded_vector);
void sort_country(vector<InternationalStudent> &loaded_vector);
void sort_province(vector<DomesticStudent> &loaded_vector);

struct CompareStudent{ // functor prototype
    int type;
    int attribute;
    int compared_value;

    CompareStudent(int attribute);
    template <class T>
    bool operator()( const T &student1, const T &student2);
};

// friend function prototypes
template <class T>
int compare_firstname(const T& student1, const T& student2);
template <class T>
int compare_lastname(const T& student1, const T& student2);
template <class T>
int compare_cgpa(const T& student1, const T& student2);
template <class T>
int compare_researchscore(const T& student1, const T& student2);
template <class T>
int compare_location(int type, const T& student1, const T& student2);

// output function prototypes
void print_vector(int selection, vector<DomesticStudent> &loaded_vector);
void print_vector(int selection, vector<InternationalStudent> &loaded_vector);

#endif // FUNCTIONS_HPP
