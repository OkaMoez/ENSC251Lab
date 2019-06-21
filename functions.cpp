#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.hpp"
#include "functions.hpp"
#include "student.hpp"
using namespace std;

// user input function implementations
// pass vectors by reference for efficiency
void start_sort(vector<DomesticStudent> &D_vector,
                vector<InternationalStudent> &I_vector){
    string user_input;
    cout << "Sort [Domestic] or [International] Students? " << endl;

    bool valid_selection = false;  // loop menu until selection is valid
    while (valid_selection != true) {
        cin >> user_input;
        cout << endl;

        // first letters are used to forgive typos
        if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')) {
            get_sort_method(DOMESTIC, D_vector);
        }
        else if ((user_input.at(0) == 'I') | (user_input.at(0) == 'i')){
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
            sort_firstname(loaded_vector);
        }
        else if ((user_input.at(0) == 'L') | (user_input.at(0) == 'l')){
            sort_lastname(loaded_vector);
        }
        else if ((user_input.at(0) == 'C') | (user_input.at(0) == 'c')){
            sort_cgpa(loaded_vector);
        }
        else if ((user_input.at(0) == 'R') | (user_input.at(0) == 'r')){
            sort_researchscore(loaded_vector);
        }
        else if ((user_input.at(0) == 'O') | (user_input.at(0) == 'o')){
            sort_overall(loaded_vector);
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
void sort_firstname(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(FIRSTNAME));
    print_vector(SELECT_BASIC, loaded_vector);
}
template <class T>
void sort_lastname(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(LASTNAME));
    print_vector(SELECT_BASIC, loaded_vector);
}
template <class T>
void sort_cgpa(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(CGPA));
    print_vector(SELECT_BASIC, loaded_vector);
}
template <class T>
void sort_researchscore(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(RESEARCHSCORE));
    print_vector(SELECT_BASIC, loaded_vector);
}
template <class T>
void sort_overall(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(OVERALL));
    print_vector(SELECT_TOELF, loaded_vector);
}
void sort_country(vector<InternationalStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(COUNTRY));
    print_vector(SELECT_BASIC, loaded_vector);
}
void sort_province(vector<DomesticStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(PROVINCE));
    print_vector(SELECT_BASIC, loaded_vector);
}

CompareStudent::CompareStudent(int attribute){this->attribute = attribute;}
template <class T>
bool CompareStudent::operator()(const T &student1, const T &student2){
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
        else if (attribute == OVERALL){
            int compared_cgpa = compare_cgpa(student1,student2);
            int compared_researchscore = compare_researchscore(student1,student2);
            int compared_location = compare_location(student1,student2);
            if ((compared_cgpa > 0) || ((compared_cgpa == 0) && (compared_researchscore > 0))
                || ((compared_cgpa == 0) && (compared_researchscore == 0) && (compared_location < 0)))
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
int compare_firstname(const T& student1, const T& student2){
    // compare results, 0 is =, 0< is <, 0> is > (alphabetically same case)
    return student1.firstname_.compare(student2.firstname_);
}

template <class T>
int compare_lastname(const T& student1, const T& student2){
    // compare results, 0 is =, 0< is <, 0> is > (alphabetically same case)
    return student1.lastname_.compare(student2.lastname_);
}

template <class T>
int compare_cgpa(const T& student1, const T& student2){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student1.cgpa_ == student2.cgpa_)
        return 0;
    else if (student1.cgpa_ < student2.cgpa_)
        return (-1);
    else
        return (1);
}

template <class T>
int compare_researchscore(const T& student1, const T& student2){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student1.researchscore_ == student2.researchscore_)
        return 0;
    else if (student1.researchscore_ < student2.researchscore_)
        return (-1);
    else
        return 1;
}

template <class T>
int compare_location(const T& student1, const T& student2){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student1.location() == student2.location())
        return 0;
    else if (student1.location() < student2.location())
        return (-1);
    else
        return 1;
}

// printing function implementation (overloaded)
void print_vector(int selection, vector<DomesticStudent> &loaded_vector){
    for(int i=0; i < signed(loaded_vector.size()); i++){
        if (selection != 0)
        cout << "Domestic student " << (i+1)
             << loaded_vector[unsigned(i)]
             << endl;;
    }
}

string ez_check(bool a){
    if (a == true)
        return "True";
    if (a == false)
        return "False";
    else {
        return "Oops";
    }
}

void print_vector(int selection, vector<InternationalStudent> &loaded_vector){
    int student_num = 1;
    if (selection == SELECT_TOELF)
        cout << "toelf" << endl;
    for(int i=0; i < signed(loaded_vector.size()); i++){
        if (selection == SELECT_BASIC){
            cout << "International student " << (student_num)
                 << loaded_vector[unsigned(i)] << endl;
            student_num++;
        }
        else if ((selection == SELECT_TOELF) && (loaded_vector[unsigned(i)].check_requirements() == true)){
            cout << "International student " << (student_num)
                 << loaded_vector[unsigned(i)] << endl;
            student_num++;
        }
    }
}
