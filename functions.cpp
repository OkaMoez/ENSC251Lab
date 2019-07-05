#include <iostream>
#include <vector>
#include <algorithm> // included to use std::sort (see https://www.geeksforgeeks.org/sort-c-stl/)
#include "functions.hpp"
#include "studentlists.hpp"
using namespace std;

// User Input Function Implementations
void StartMenu(StudentList &D_list/*,
                IStudentList &I_List*/){
    string user_input;

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Interact with [Domestic] Students, [International] Students, or [Both]? " << endl;
        cin >> user_input;

        // First letters are used to forgive typos.
        if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')) {
            ListMenu(kDomestic, D_list);
        }
        else if ((user_input.at(0) == 'I') | (user_input.at(0) == 'i')){
            //get_sort_method(kInternational, I_vector);
        }

        else if ((user_input.at(0) == 'B') | (user_input.at(0) == 'b')){
            //get_sort_method(kInternational, I_vector);
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q')){
            valid_selection = true;
        }
        else
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please enter [International], [Domestic], or [Quit]."
                 << endl;
    }
}
void ListMenu(int student_type, StudentList &loaded_list)
{
    string user_input;

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Choose to [Search], [Add] a New Student, [Delete] a Student, or [Reprint] the List? " << endl;
        cin >> user_input;

        // First letters are used to forgive typos.
        if ((user_input.at(0) == 'S') | (user_input.at(0) == 's')) {
            SearchType(student_type, loaded_list);
        }
        else if ((user_input.at(0) == 'A') | (user_input.at(0) == 'a')){
            MakeNewStudent(student_type, loaded_list);
        }

        else if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')){
            SearchAndDestroy(loaded_list);
        }
        else if ((user_input.at(0) == 'R') | (user_input.at(0) == 'r')){
            loaded_list.PrintList();
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q')){
            valid_selection = true;
        }
        else
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please enter [International], [Domestic], or [Quit]."
                 << endl;
    }
}
void SearchType(int student_type, StudentList &loaded_list)
{
    string user_input;
    string text = kStudentWordList[student_type];
    int search_type = 0;
    bool search_ready = false;

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Search " << text << " students by [Name], "
             << "or by [CGPA] and research score?" << endl;
        cin >> user_input;

        // First letters are used to forgive typos.
        if ((user_input.at(0) == 'N') | (user_input.at(0) == 'n')) {
            search_type = kFirstName;
            search_ready = true;
        }
        else if ((user_input.at(0) == 'C') | (user_input.at(0) == 'c')){
            search_type = kCgpa;
            search_ready = true;
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q'))
            valid_selection = true;
        else{
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please select [First], [CGPA], or [Quit]."
                 << endl;
        }
        if (search_ready == true){
            Search(search_type, loaded_list);
        }
        search_ready = false;
    }
}
void Search(int search_type, StudentList &loaded_list)
{
    if((search_type == kFirstName) | (search_type == kCgpa)){
        string target_firstname = kStudentWordList[kFirstName];
        string target_lastname = kStudentWordList[kLastName];
        float target_cgpa = kCgpa;
        int target_researchscore = kResearchScore;

        Node *previous = new Node;
        Node *current = new Node;
        *current = loaded_list.head();

        if (search_type == kFirstName){
            target_firstname = GetTarget(target_firstname);
            target_lastname = GetTarget(target_lastname);
        }
        else if (search_type == kCgpa) {
            target_cgpa = GetTarget(target_cgpa);
            target_researchscore = GetTarget(target_researchscore);
        }

        for(int i=0; i<loaded_list.list_length(); i++){
            if (search_type == kFirstName){
                if((current ->a_student_.firstname() == target_firstname) &&
                  (current ->a_student_.lastname() == target_lastname)){
                    cout << current -> a_student_ << endl;
                }
            }
            else if (search_type == kCgpa) {
                if((current ->a_student_.cgpa() == target_cgpa) &&
                  (current ->a_student_.researchscore() == target_researchscore)){
                    cout << current -> a_student_ << endl;
                }
            }
            previous = current;
            current = current -> next_;
        }
    }
    else
        cout << "Error: Untyped Search Request" << endl;
}
void MakeNewStudent(int student_type, StudentList &loaded_list){
    string user_input;
    string first_name_input;
    string last_name_input;
    string location_input;
    float cgpa_input;
    int researchscore_input;
    Student newStudent;
    DomesticStudent newDStudent;
    InternationalStudent newIStudent;
    string text = kStudentWordList[student_type];

    bool done = false;
    while(done != true){
        cout << "To create a new " << text << " student, please input the following: " << endl
             << "First name: ";
        cin >> first_name_input;
        first_name_input = CleanNameInput(first_name_input);
        cout << "Last name: ";
        cin >> last_name_input;
        last_name_input = CleanNameInput(last_name_input);
        cout << "CGPA: ";
        cin >> cgpa_input;
        cout << "Research Score: ";
        cin >> researchscore_input;
        if(student_type == kDomestic){
            cout << "Province: ";
        }
        else {
            cout << "Country: ";
        }
        cin >> location_input;
        if(student_type == kInternational){ // OH DEAR.
            cout << "Toelf Scores: ";
            //cin >>
        }
        else {
            //newDStudent = DomesticStudent(first_name_input, last_name_input, cgpa_input, researchscore_input, location_input);
            //loaded_list.NewStudent(*newDStudent);
            //newStudent = *newDStudent;
        }
        cout << "Please confirm details. [Yes/No]" << endl
             << newStudent;
        cin >> user_input;
        if((user_input.at(0) == 'Y') | (user_input.at(0) == 'y')){
            done = true;
        }
    }

}
void SearchAndDestroy(StudentList &loaded_list){
    string target_firstname = GetTarget(kStudentWordList[kFirstName]);
    string target_lastname = GetTarget(kStudentWordList[kLastName]);
    Node *previous = new Node;
    Node *current = new Node;
    *current = loaded_list.head();

    for(int i=0; i<loaded_list.list_length(); i++){
            if((current ->a_student_.firstname() == target_firstname) &&
              (current ->a_student_.lastname() == target_lastname)){
                loaded_list.DeleteStudent(i+1);
            }
        previous = current;
        current = current -> next_;
    }

}
string GetTarget(string target_type){
    string user_input;

    cout << "Please type the " << target_type << " to search by: " << endl;
    cin >> user_input;
    user_input = CleanNameInput(user_input);
    return user_input;
}
float GetTarget(float target_type){
    float user_input = target_type;
    cout << "Please type the CGPA to search by: " << endl;
    cin >> user_input;
    return user_input;
}
int GetTarget(int target_type){
    int user_input = target_type;
    cout << "Please type the research score to search by: " << endl;
    cin >> user_input;
    return user_input;
}
string CleanNameInput(string user_input){
    // Conditioning input.
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
    // Removing whitespace. (See: https://www.techiedelight.com/remove-whitespaces-string-cpp/)
    user_input.erase(std::remove_if(user_input.begin(), user_input.end(),
                           [](char &c) {return std::isspace<char>(c, std::locale::classic());                            }),
                            user_input.end());
    // Set first letter case.
    user_input[0] = toupper(user_input[0]);
    return user_input;
}

// Sorting Function Implementations
CompareStudent::CompareStudent(int attribute){this->attribute = attribute;}
//template <class T>
bool CompareStudent::operator()(const Student &student1, const Student &student2){
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
            if ((compared_cgpa > 0) ||
               ((compared_cgpa == 0) && (compared_researchscore > 0)) ||
               ((compared_cgpa == 0) && (compared_researchscore == 0) && (compared_location < 0)))
                return true;
            else
                return false;
        }
        else
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
template <class T>
int compare_location(const T& student1, const T& student2){
    if (student1.location() == student2.location())
        return 0;
    else if (student1.location() < student2.location())
        return (-1);
    else
        return 1;
}
