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
void sort_firstname(int type, vector<T> &loaded_vector);
template <class T>
void sort_lastname(int type, vector<T> &loaded_vector);
template <class T>
void sort_cgpa(int type, vector<T> &loaded_vector);
template <class T>
void sort_researchscore(int type, vector<T> &loaded_vector);
template <class T>
void sort_overall(int type, vector<T> &loaded_vector);
void sort_country(vector<InternationalStudent> &loaded_vector);
void sort_province(vector<DomesticStudent> &loaded_vector);


// friend function prototypes
int compare_firstname(string student_a, string student_b);
int compare_lastname(string student_a, string student_b);
int compare_cgpa(int student_a, int student_b);
int compare_researchscore(int student_a, int student_b);

// output function prototypes
template <class T>
void print_vector(int type, vector<T> &loaded_vector);

#endif // FUNCTIONS_HPP
