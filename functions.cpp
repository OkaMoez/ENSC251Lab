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
        if (user_input.at(0) == ('D' | 'd')) {
            //valid_selection = true; // set loop to end and call sort function
            get_sort_method(DOMESTIC, D_vector);
        }
        else if (user_input.at(0) == ('I' | 'i')){
            //valid_selection = true; // set loop to end and call sort function
            get_sort_method(INTERNATIONAL, I_vector);
        }
        else if (user_input.at(0) == ('Q' | 'q'))
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

    cout << "Sort " << text << " students by [First] name, [Last] name, "
         << "[CGPA], [Research] score, or [Overall] academics?" << endl;

    bool valid_selection = false;

    while (valid_selection != true) { // loop menu until selection is valid
        cin >> user_input; // take input
        cout << endl;

        // first letters are used to forgive typos
        if (user_input.at(0) == ('F' | 'f')) {
            valid_selection = true; // set loop to end and call sort function
            sort_firstname(type, loaded_vector);
        }
        else if (user_input.at(0) == ('L' | 'l')){
            valid_selection = true; // set loop to end and call sort function
            sort_lastname(type, loaded_vector);
        }
        else if (user_input.at(0) == ('C' | 'c')){
            valid_selection = true; // set loop to end and call sort function
            sort_cgpa(type, loaded_vector);
        }
        else if (user_input.at(0) == ('R' | 'r')){
            valid_selection = true; // set loop to end and call sort function
            sort_researchscore(type, loaded_vector);
        }
        else if (user_input.at(0) == ('O' | 'o')){
            valid_selection = true; // set loop to end and call sort function
            sort_overall(type, loaded_vector);
        }
        else if (user_input.at(0) == ('Q' | 'q'))
            exit(1); // give user a way out
        else
            cout << "Invalid input. " // correct invalid inputs
                 << "Please select [First], [Last], "
                 << "[CGPA], [Research], [Overall], or [Quit]."
                 << endl;
    }
}

// sorting function implementations
struct CompareStudent{
    int attribute;
    CompareStudent(int attribute) {this->attribute = attribute;}
    bool operator()( const Student &student1, const Student &student2)const{
        if (attribute == FIRSTNAME)
            return student1.firstname() < student2.firstname();
        else if (attribute == LASTNAME)
            return student1.lastname() < student2.lastname();
        else if (attribute == CGPA)
            return student1.cgpa() < student2.cgpa();
        else if (attribute == RESEARCHSCORE)
            return student1.researchscore() < student2.researchscore();
        else
            exit(1);
    }
};

template <class T>
void sort_firstname(int type, vector<T> &loaded_vector){
    sort(loaded_vector.begin(), loaded_vector.end(), CompareStudent(FIRSTNAME));
    print_vector(type, loaded_vector);
}
template <class T>
void sort_lastname(int type, vector<T> &loaded_vector){

}
template <class T>
void sort_cgpa(int type, vector<T> &loaded_vector){

}
template <class T>
void sort_researchscore(int type, vector<T> &loaded_vector){

}
template <class T>
void sort_overall(int type, vector<T> &loaded_vector){

}
void sort_country(int type, vector<InternationalStudent> &loaded_vector){

}
void sort_province(int type, vector<DomesticStudent> &loaded_vector){

}

// friend function implementations
int compare_firstname(string student_a, string student_b){
    // compare results, 0 is =, -1 is <, 1 is > (alphabetically same case)
    return student_a.compare(student_b);
}

int compare_lastname(string student_a, string student_b){
    // compare results, 0 is =, -1 is <, 1 is > (alphabetically same case)
    return student_a.compare(student_b);
}

int compare_cgpa(int student_a, int student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a == student_b)
        return 0;
    else if (student_a < student_b)
        return (-1);
    else
        return 0;
}

int compare_researchscore(int student_a, int student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a == student_b)
        return 0;
    else if (student_a < student_b)
        return (-1);
    else
        return 0;
}

// printing function implementation
template <class T>
void print_vector(int type, vector<T> &loaded_vector){
    string text;
    if (type == DOMESTIC)
        text = "Domestic";
    else
        text = "International";

    for(int i=0; i < loaded_vector.size(); i++){
        cout << text << " student " << (i+1)
             << loaded_vector[i]
             << endl;
    }
}
