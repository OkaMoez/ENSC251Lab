#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.hpp"
#include "functions.hpp"
#include "student.hpp"
using namespace std;

// user input function implementations
// pass vectors by reference for speed
void start_sort(vector<DomesticStudent> &D_vector,
                vector<InternationalStudent> &I_vector){
    string user_input;
    cout << "Sort [Domestic] or [International] Students? " << endl;

    bool valid_selection = false;

    while (valid_selection != true) { // loop menu until selection is valid
        cin >> user_input; // take input
        cout << endl;

        // first letters are used to forgive typos
        if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')) {
            //valid_selection = true; // set loop to end and call sort function
            get_sort_method(DOMESTIC, D_vector);
        }
        else if ((user_input.at(0) == 'I') | (user_input.at(0) == 'i')){
            //valid_selection = true; // set loop to end and call sort function
            get_sort_method(INTERNATIONAL, I_vector);
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q'))
            exit(1); // give user a way out
        else
            cout << "Invalid input. " // correct invalid inputs
                 << "Please enter [International], [Domestic], or [Quit]."
                 << endl;
    }
}

template <class T> // allow function to take either student type
void get_sort_method(int type, vector<T> &loaded_vector){
    string user_input;
    string text;

    if (type == DOMESTIC)
        text = "domestic";
    else
        text = "international";

    bool valid_selection = false;

    while (valid_selection != true) { // loop menu until selection is valid
        cout << "Sort " << text << " students by [First] name, [Last] name, "
             << "[CGPA], [Research] score, or [Overall] academics?" << endl;

        cin >> user_input; // take input
        cout << endl;

        // first letters are used to forgive typos
        if ((user_input.at(0) == 'F') | (user_input.at(0) == 'f')) {
            //valid_selection = true; // set loop to end and call sort function
            sort_firstname(type, loaded_vector);
        }
        else if ((user_input.at(0) == 'L') | (user_input.at(0) == 'l')){
            //valid_selection = true; // set loop to end and call sort function
            sort_lastname(type, loaded_vector);
        }
        else if ((user_input.at(0) == 'C') | (user_input.at(0) == 'c')){
            //valid_selection = true; // set loop to end and call sort function
            sort_cgpa(type, loaded_vector);
        }
        else if ((user_input.at(0) == 'R') | (user_input.at(0) == 'r')){
            //valid_selection = true; // set loop to end and call sort function
            sort_researchscore(type, loaded_vector);
        }
        else if ((user_input.at(0) == 'O') | (user_input.at(0) == 'o')){
            //valid_selection = true; // set loop to end and call sort function
            sort_overall(type, loaded_vector);
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q'))
            exit(1); // give user a way out
        else
            cout << "Invalid input. " // correct invalid inputs
                 << "Please select [First], [Last], "
                 << "[CGPA], [Research], [Overall], or [Quit]."
                 << endl;
    }
}

// sorting function implementations
template <class T>
void sort_firstname(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(FIRSTNAME));
    print_vector(type, loaded_vector);
}
template <class T>
void sort_lastname(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(LASTNAME));
    print_vector(type, loaded_vector);
}
template <class T>
void sort_cgpa(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(CGPA));
    print_vector(type, loaded_vector);
}
template <class T>
void sort_researchscore(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(RESEARCHSCORE));
    print_vector(type, loaded_vector);
}
template <class T>
void sort_overall(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(CGPA));
    print_vector(type, loaded_vector);
}
void sort_country(int type, vector<InternationalStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(COUNTRY));
    print_vector(type, loaded_vector);
}
void sort_province(int type, vector<DomesticStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(PROVINCE));
    print_vector(type, loaded_vector);
}

CompareStudent::CompareStudent(int attribute){this->attribute = attribute;}
template <class T>
bool CompareStudent::operator()( const T &student1, const T &student2){
        if (attribute == FIRSTNAME){
            compared_value = compare_firstname(student1,student2);
            if (compared_value < 0)
                return true;
            else
                return false;
        }
        else if (attribute == LASTNAME){
            compared_value = compare_lastname(student1,student2);
            if (compared_value < 0)
                return true;
            else
                return false;
        }
        else if (attribute == CGPA){
            compared_value = compare_cgpa(student1,student2);
            if (compared_value > 0)
                return true;
            else
                return false;
        }
        else if (attribute == RESEARCHSCORE){
            compared_value = compare_researchscore(student1,student2);
            if (compared_value > 0)
                return true;
            else
                return false;
        }
        else
            return false;
        return false;
};

// friend function implementations
template <class T>
int compare_firstname(const T& student_a, const T& student_b){
    // compare results, 0 is =, 0< is <, 0> is > (alphabetically same case)
    return student_a.firstname_.compare(student_b.firstname_);
}

template <class T>
int compare_lastname(const T& student_a, const T& student_b){
    // compare results, 0 is =, 0< is <, 0> is > (alphabetically same case)
    return student_a.lastname_.compare(student_b.lastname_);
}

template <class T>
int compare_cgpa(const T& student_a, const T& student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a.cgpa_ == student_b.cgpa_)
        return 0;
    else if (student_a.cgpa_ < student_b.cgpa_)
        return (-1);
    else
        return (1);
}

template <class T>
int compare_researchscore(const T& student_a, const T& student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a.researchscore_ == student_b.researchscore_)
        return 0;
    else if (student_a.researchscore_ < student_b.researchscore_)
        return (-1);
    else
        return 1;
}

// printing function implementation
template <class T>
void print_vector(int type, vector<T> &loaded_vector){
    string text;
    if (type == DOMESTIC)
        text = "Domestic";
    else
        text = "International";

    for(int i=0; i < signed(loaded_vector.size()); i++){
        cout << text << " student " << (i+1)
             << loaded_vector[unsigned(i)]
             << endl;
    }
}
