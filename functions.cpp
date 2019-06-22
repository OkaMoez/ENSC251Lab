#include <iostream>
#include <vector>
#include <algorithm> // included to use std::sort (see https://www.geeksforgeeks.org/sort-c-stl/)
#include "constants.hpp"
#include "functions.hpp"
#include "student.hpp"
using namespace std;

// User Input Function Implementations
// Vectors are passed by reference for efficiency.
void start_sort(vector<DomesticStudent> &D_vector,
                vector<InternationalStudent> &I_vector){
    string user_input;

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Sort [Domestic] or [International] Students? " << endl;
        cin >> user_input;
        cout << endl;

        // First letters are used to forgive typos.
        if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')) {
            get_sort_method(kDomestic, D_vector);
        }
        else if ((user_input.at(0) == 'I') | (user_input.at(0) == 'i')){
            get_sort_method(kInternational, I_vector);
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q'))
            valid_selection = true;
        else
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please enter [International], [Domestic], or [Quit]."
                 << endl;
    }
}

template <class T> // Allows function to take either student type.
void get_sort_method(int type, vector<T> &loaded_vector){
    string user_input;
    string text;

    if (type == kDomestic)
        text = "domestic";
    else
        text = "international";

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Sort " << text << " students by [First] name, [Last] name, "
             << "[CGPA], [Research] score, or [Overall] academics?" << endl;
        cin >> user_input;
        cout << endl;

        // First letters are used to forgive typos.
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
            valid_selection = true;
        else
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please select [First], [Last], "
                 << "[CGPA], [Research], [Overall], or [Quit]."
                 << endl;
    }
}

// Sorting Function Implementations
template <class T>
void sort_firstname(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kFirstName));
    print_vector(kSelectBasic, loaded_vector);
}
template <class T>
void sort_lastname(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kLastName));
    print_vector(kSelectBasic, loaded_vector);
}
template <class T>
void sort_cgpa(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kCgpa));
    print_vector(kSelectBasic, loaded_vector);
}
template <class T>
void sort_researchscore(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kResearchScore));
    print_vector(kSelectBasic, loaded_vector);
}
template <class T>
void sort_overall(vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kOverall));
    print_vector(kSelectToelf, loaded_vector);
}
void sort_country(vector<InternationalStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kCountry));
    print_vector(kSelectBasic, loaded_vector);
}
void sort_province(vector<DomesticStudent> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(kProvince));
    print_vector(kSelectBasic, loaded_vector);
}

CompareStudent::CompareStudent(int attribute){this->attribute = attribute;}
template <class T>
bool CompareStudent::operator()(const T &student1, const T &student2){
        if (attribute == kFirstName){
            compared_value = compare_firstname(student1,student2);
            if (compared_value < 0)
                return true;
            else
                return false;
        }
        else if (attribute == kLastName){
            compared_value = compare_lastname(student1,student2);
            if (compared_value < 0)
                return true;
            else
                return false;
        }
        else if (attribute == kCgpa){
            compared_value = compare_cgpa(student1,student2);
            if (compared_value > 0)
                return true;
            else
                return false;
        }
        else if (attribute == kResearchScore){
            compared_value = compare_researchscore(student1,student2);
            if (compared_value > 0)
                return true;
            else
                return false;
        }
        else if (attribute == kOverall){
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

// Friend Function Implementations
// These compare student derivative objects.
// Their output can be interpreted as follows: 0 is =, 0< is <, 0> is >.
// Char comparisons at a<z<A<Z.
template <class T>
int compare_firstname(const T& student1, const T& student2){
    return student1.firstname_.compare(student2.firstname_);
}
template <class T>
int compare_lastname(const T& student1, const T& student2){
    return student1.lastname_.compare(student2.lastname_);
}
template <class T>
int compare_cgpa(const T& student1, const T& student2){
    if (student1.cgpa_ == student2.cgpa_)
        return 0;
    else if (student1.cgpa_ < student2.cgpa_)
        return (-1);
    else
        return (1);
}
template <class T>
int compare_researchscore(const T& student1, const T& student2){
    if (student1.researchscore_ == student2.researchscore_)
        return 0;
    else if (student1.researchscore_ < student2.researchscore_)
        return (-1);
    else
        return 1;
}
// Compare location is overloaded to allow comparing both province and country.
// This was an issue previously using templates.
int compare_location(const DomesticStudent& student1, const DomesticStudent& student2){
    if (student1.province() == student2.province())
        return 0;
    else if (student1.province() < student2.province())
        return (-1);
    else
        return 1;
}
int compare_location(const InternationalStudent& student1, const InternationalStudent& student2){
    if (student1.country() == student2.country())
        return 0;
    else if (student1.country() < student2.country())
        return (-1);
    else
        return 1;
}

// Printing Function Implementation (overloaded)
void print_vector(int selection, vector<DomesticStudent> &loaded_vector){
    for(int i=0; i < signed(loaded_vector.size()); i++){
        if (selection != 0) // for possible future filters/to remove warning
        cout << "Domestic student " << (i+1)
             << loaded_vector[unsigned(i)]
             << endl;;
    }
}

void print_vector(int selection, vector<InternationalStudent> &loaded_vector){
    int student_num = 1;
    for(int i=0; i < signed(loaded_vector.size()); i++){
        if (selection == kSelectBasic){ // Regular filter/no filter prints all.
            cout << "International student " << (student_num)
                 << loaded_vector[unsigned(i)] << endl;
            student_num++;
        }
        // Toelf filter avoids printing objects under cut-off during overall sorting.
        else if ((selection == kSelectToelf) && (loaded_vector[unsigned(i)].check_requirements() == true)){
            cout << "International student " << (student_num)
                 << loaded_vector[unsigned(i)] << endl;
            student_num++;
        }
    }
}
