#include <iostream>
#include <vector>
#include <algorithm> // included to use std::sort (see https://www.geeksforgeeks.org/sort-c-stl/)
#include "functions.hpp"
#include "studentlists.hpp"
using namespace std;

// User Input Function Implementations
void StartMenu(StudentList &D_list,
                StudentList &I_list){
    string user_input;
    StudentList B_list = MergeList(D_list, I_list);

    bool valid_selection = false;  // Loop continues until user chooses to quit.
    while (valid_selection != true) {
        cout << "Interact with [Domestic] Students, [International] Students, or [Both]? " << endl;
        cin >> user_input;

        // First letters are used to forgive typos.
        if ((user_input.at(0) == 'D') | (user_input.at(0) == 'd')) {
            D_list.PrintList();
            ListMenu(kDomestic, D_list);
        }
        else if ((user_input.at(0) == 'I') | (user_input.at(0) == 'i')){
            I_list.PrintList();
            ListMenu(kInternational, I_list);
        }

        else if ((user_input.at(0) == 'B') | (user_input.at(0) == 'b')){
            B_list.PrintList();
            ListMenu(kOverall, B_list);
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
                 << "Please enter [Search], [Add], [Delete], [Reprint], or [Quit]."
                 << endl;
    }
}
StudentList MergeList(StudentList &list1, StudentList &list2){
    StudentList list_out(list1);

    Node *current = new Node;
    *current = list2.head();
    for(int i=0; i<list2.list_length(); i++){
        list_out.NewStudent(current->a_student_);
        current = current -> next_;
    }

    return list_out;
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
        else if ((user_input.at(0) == 'C') | (user_input.at(0) == 'c')
                 | (user_input.at(0) == 'R') | (user_input.at(0) == 'r')){
            search_type = kCgpa;
            search_ready = true;
        }
        else if ((user_input.at(0) == 'Q') | (user_input.at(0) == 'q'))
            valid_selection = true;
        else{
            cout << "Invalid input. " // Looped text is to help user correct invalid inputs.
                 << "Please select [Name], [CGPA], [Research], or [Quit]."
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

        Node *current = new Node;
        *current = loaded_list.head();

        if (search_type == kFirstName){
            target_firstname = GetString(kFirstName);
            target_lastname = GetString(kLastName);
        }
        else if (search_type == kCgpa) {
            target_cgpa = GetCGPA();
            target_researchscore = GetIntScore(kResearchScore);
        }

        for(int i=0; i<loaded_list.list_length(); i++){
            if (search_type == kFirstName){
                if((current ->a_student_->firstname() == target_firstname) &&
                  (current ->a_student_->lastname() == target_lastname)){
                    cout << current -> a_student_ << endl;
                }
            }
            else if (search_type == kCgpa) {
                if ((current ->a_student_->cgpa() == target_cgpa)) {
                    if((current ->a_student_->researchscore() == target_researchscore)){
                        cout << current -> a_student_ << endl;
                    }
                }
            }
            current = current -> next_;
        }
    }
    else
        cout << "Error: Untyped Search Request" << endl;
}
void SearchAndDestroy(StudentList &loaded_list){
    string target_firstname = GetString(kFirstName);
    string target_lastname = GetString(kLastName);
    Node *current = new Node;
    int count = 0;
    *current = loaded_list.head();

    for(int i=0; i<loaded_list.list_length(); i++){
        count++;
            if((current ->a_student_->firstname() == target_firstname) &&
              (current ->a_student_->lastname() == target_lastname)){
                loaded_list.DeleteStudent(count);
                count--;
            }
        current = current -> next_;
    }

}
void MakeNewStudent(int student_type, StudentList &loaded_list){
    string user_input;
    string first_name_input;
    string last_name_input;
    string location_input;
    float cgpa_input;
    int researchscore_input;
    int reading_input;
    int listening_input;
    int speaking_input;
    int writing_input;
    Student newStudent;
    InternationalStudent newIStudent;
    string text = kStudentWordList[student_type];

    bool done = false;
    while(done != true){
        cout << "To create a new " << text << " student, please input the following: " << endl
             << "First name: ";
        first_name_input = GetString(kFirstName);
        cout << "Last name: ";
        cin >> last_name_input;
        last_name_input = GetString(kLastName);
        cout << "CGPA: ";
        cgpa_input = GetCGPA();
        cout << "Research Score: ";
        researchscore_input = GetIntScore(kResearchScore);
        if(student_type == kDomestic){
            cout << "Province: ";
            location_input = GetString(kProvince);
        }
        else {
            cout << "Country: ";
            location_input = GetString(kCountry);
        }
        if(student_type == kInternational){
            cout << "Toelf Reading: ";
            reading_input = GetIntScore(kReading);
            cout << "Toelf Listening: ";
            listening_input = GetIntScore(kListening);
            cout << "Toelf Speaking: ";
            speaking_input = GetIntScore(kSpeaking);
            cout << "Toelf Writing: ";
            writing_input = GetIntScore(kWriting);
            Student* newStudent = new InternationalStudent(first_name_input, last_name_input, cgpa_input, researchscore_input, location_input,
                                                           reading_input, listening_input, speaking_input, writing_input);
            loaded_list.NewStudent(newStudent);

        }
        else {
            Student* newStudent = new DomesticStudent(first_name_input, last_name_input, cgpa_input, researchscore_input, location_input);
            loaded_list.NewStudent(newStudent);
        }
        cout << "Please confirm details. [Yes/No]" << endl
             << newStudent;
        cin >> user_input;
        if((user_input.at(0) == 'Y') | (user_input.at(0) == 'y')){
            done = true;
        }
    }

}
string GetString(int target_type){
    string user_input = " ";

    cout << "Please input a " << kStudentWordList[target_type] << ": " << endl;
    bool valid_input = false;
    while(valid_input != true){
        cin >> user_input;
        if (target_type == kProvince){
            user_input = CleanProvinceInput(user_input);
            if (find(begin(kProvinceList), end(kProvinceList), user_input) != end(kProvinceList)) {
                valid_input = true;
            }
            else {
                cout << "Invalid input. \n" << "Input a valid province" << endl;
            }
        }
        else {
            user_input = CleanPNounInput(user_input);
            valid_input = true;
            for (int unsigned i = 0; user_input[i] != '\0'; i++) {
                if (isdigit(user_input[i]) != 0) {
                    cout << "Invalid input. \n" << "Non-alphabetic characters detected." << endl;
                    cout << "Input a " << kStudentWordList[target_type] << endl;
                    valid_input = false;
                    break;
                }
            }
        }
    }
    return user_input;
}
float GetCGPA(){
    float user_input = 0;
    cout << "Please input a CGPA: " << endl;
    bool valid_input = false;
    while(valid_input != true){
        cin >> user_input;
        if ((user_input >= 0) && (user_input <= float(4.33)))
            valid_input = true;
        else
            cout << "Invalid input. \n" << "Input a valid CGPA between 0 and 4.33" << endl;
    }
    return user_input;
}
int GetIntScore(int target_type){
    int user_input = 0;
    cout << "Please type the " << target_type <<" to search by: " << endl;
    bool valid_input = false;
    while(valid_input != true){
        cin >> user_input;
        if ((target_type == kResearchScore)&&((user_input >= 0) && (user_input <= 100)))
            valid_input = true;
        if (((target_type == kReading) || (target_type == kSpeaking) ||
           (target_type == kListening) || (target_type == kWriting)) &&
           ((user_input >= 0) && (user_input <= 30)))
            valid_input = true;
        else
            cout << "Invalid input. \n" << "Input a valid " << target_type << " between "
                 << kRangeList[target_type] << "." << endl;
    }
    return user_input;
}
string CleanPNounInput(string user_input){
    // Conditioning input.
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
    // Removing whitespace.
    user_input = CleanCharacter(user_input, kWhitespace);
    // Set first letter case.
    user_input[0] = toupper(user_input[0]);
    return user_input;
}
string CleanProvinceInput(string user_input){
    // Conditioning input.
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
    // Removing whitespace.
    user_input = CleanCharacter(user_input, kWhitespace);
    return user_input;
}

string CleanCharacter(string string_in, char char_in){
    string string_out = "";
    for (int unsigned i = 0; string_in[i] != '\0'; i++){
        if ((string_in)[i] != char_in){
            string_out.push_back(string_in[i]);
        }
    }
    return string_out;
}

// Sorting Function Implementations
CompareStudent::CompareStudent(int attribute){this->attribute = attribute;}
bool CompareStudent::operator()(const Student &student1, const Student &student2){
        if (attribute == kFirstName){
            int compared_firstname = compare_firstname(student1,student2);
            if (compared_firstname < 0)
                return true;
            else
                return false;
        }
        else if (attribute == kLastName){
            int compared_lastname = compare_lastname(student1,student2);
            if (compared_lastname < 0)
                return true;
            else
                return false;
        }
        else if (attribute == kCgpa){
            int compared_firstname = compare_firstname(student1,student2);
            int compared_cgpa = compare_cgpa(student1,student2);
            if ((compared_cgpa > 0)||
               ((compared_cgpa == 0) && (compared_firstname < 0)))
                return true;
            else
                return false;
        }
        else if (attribute == kResearchScore){
            int compared_firstname = compare_firstname(student1,student2);
            int compared_researchscore = compare_researchscore(student1,student2);
            if ((compared_researchscore > 0)||
               ((compared_researchscore == 0) && (compared_firstname < 0)))
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
    if (student1.cgpa_ == student2.cgpa_){
        return 0;}
    else if (student1.cgpa_ < student2.cgpa_){
        return (-1);}
    else{
        return (1);}
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
    if (student1.student_type() > student2.student_type())
        return 1;
    else if (student1.student_type() < student2.student_type())
        return (-1);
    else if(student1.location() == student2.location())
        return 0;
    else if (student1.location() < student2.location())
        return (-1);
    else
        return 1;
}

// Std::Replacement Functions
bool StringContains(string string_in, char char_in){
    for (int unsigned i = 0; (string_in)[i] != '\0'; i++){
        if ((string_in)[i] == char_in){
            return true;
        }
    }
    return false;
}

bool StringArrayContains(const string array_in[], string string_in){
    for (int unsigned i = 0; (array_in)[i] != "N/A"; i++){
        if ((array_in)[i] == string_in){
            return true;
        }
    }
    return false;
}
