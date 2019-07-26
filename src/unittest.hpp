#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <sstream>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "functions.hpp"

void PopulateStudentList (int student_type, StudentList& student_list, string file_path, int debug);
bool TestInsert(StudentList& test_students, Student* student1, Student* student2,
                Student* student3, Student* student4);
bool TestSearchName(StudentList& test_students);
bool TestSearchCgpa(StudentList& test_students);
bool TestDelete(StudentList& test_students);

void RunUnitTests(){
    cout << "***********************" << endl;
    cout << "Preparing Unit Tests " << endl;

    // Use Existing List
    StudentList test_students;
    PopulateStudentList(kDomestic, test_students, "domestic-stu.txt", 0);

    // Students to Insert
    // Normal Student (No matching attributes)(
    Student* student1 = new DomesticStudent("Kevin", "Todd", float(3.99), 100, "AB");
    // Corner Case Students (Some Matching Fields)
    Student* student2 = new DomesticStudent("Mary", "White", 4.00, 84, "BC");
    Student* student3 = new DomesticStudent("Mary", "White", 4.00, 85, "SK");
    // Illegal Case Students? (What's an Illegal Case here?)
    // Illegal Case Student (All Matching Fields?)
    Student* student4 = new DomesticStudent("Mary", "White",4.00, 85, "BC");

    cout << "Running Unit Tests: " << endl;

    bool passI = TestInsert(test_students, student1, student2, student3, student4);
    bool passSN = TestSearchName(test_students);
    bool passSC = TestSearchCgpa(test_students);
    bool passD = TestDelete(test_students);

    // cout << "Cleaning Up Unit Tests " << endl;

    cout << endl << "***********************" << endl;
    cout << "Report: " << endl;
    if (passI && passSN && passSC && passD) {
        cout << "Full Unit Test Success!" << endl;
    }
    else {
        cout << boolalpha;
        cout << "Unit Test Failure :(" << endl;
        cout << "Insertion Test Pass: " << passI << endl;
        cout << "Search Name Test Pass: " << passSN << endl;
        cout << "Search CGPA Test Pass: " << passSC << endl;
        cout << "Deletion Test Pass: " << passD << endl;
    }
    cout << "***********************" << endl << endl;
}
bool TestInsert(StudentList& test_students, Student* student1, Student* student2,
                Student* student3, Student* student4){
    // Normal Case, No Matching Students
    try {
        test_students.NewStudent(student1);
        cout << "Insertion Success on Student 1" << endl;
    } catch (...) {
        cout << "Insertion Failure on Student 1" << endl;
        return false;
    }
    // Corner Case 1, Matching CGPA
    try {
        test_students.NewStudent(student2);
        cout << "Insertion Success on Student 2" << endl;
    } catch (...) {
        cout << "Insertion Failure on Student 2" << endl;
        return false;
    }
    // Corner Case 2, Matching CGPA and Research Score
    try {
        test_students.NewStudent(student3);
        cout << "Insertion Success on Student 3" << endl;
    } catch (...) {
        cout << "Insertion Failure on Student 3" << endl;
        return false;
    }
    try {
        //test_students.NewStudent(1);
        //cout << "Insertion Error on Student 4 Uncaught" << endl;
    } catch (...) {
        cout << "Insertion Expected Error on Student 4" << endl;
        return false;
    }
    // Verify Order?
    test_students.PrintList();
    return true;
}
bool TestSearchName(StudentList& test_students){
    string firstname = "Zaccccc";
    string firstname1 = "Kevin";
    string lastname1 = "Todd";
    string firstname2 = "Mary";
    string lastname2 = "White";
    float cgpa = float(3.99);
    int rscore = 100;

    // No Results
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstname, lastname1, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == "");
        if (the_stream && the_stream.str() == "") {
            cout << "Search No Name Success" << endl;
        }
    } catch (...) {
        cout << "Search No Name Failure" << endl;
    }
    // Single Result
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstname1, lastname1, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == " Kevin Todd from AB has a CGPA of 3.99, and a research score of 100\n");
        if (the_stream && the_stream.str() == " Kevin Todd from AB has a CGPA of 3.99, and a research score of 100\n") {
            cout << "Search Single Name Success" << endl;
        }
    } catch (...) {
        cout << "Search Single Name Failure" << endl;
    }
    // Multiple Results
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstname2, lastname2, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == " Mary White from BC has a CGPA of 4, and a research score of 85\n "
        "Mary White from SK has a CGPA of 4, and a research score of 85\n "
        "Mary White from BC has a CGPA of 4, and a research score of 84\n");
        if (the_stream && the_stream.str() == " Mary White from BC has a CGPA of 4, and a research score of 85\n "
                "Mary White from SK has a CGPA of 4, and a research score of 85\n "
                "Mary White from BC has a CGPA of 4, and a research score of 84\n") {
            cout << "Search Multiple Name Success" << endl;
        }
    } catch (...) {
        cout << "Search Multiple Name Failure" << endl;
    }


    return true;
}
bool TestSearchCgpa(StudentList& test_students){
    string firstname = "Kevin";
    string lastname = "Todd";
    float cgpa = float(3.98);
    int rscore = 1;
    float cgpa1 = float(3.99);
    int rscore1 = 100;
    float cgpa2 = float(4.33);
    int rscore2 = 99;

    // No Results
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kCgpa, firstname, lastname, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == "");
        if (the_stream && the_stream.str() == "") {
            cout << "Search No CGPA Success" << endl;
        }
    } catch (...) {
        cout << "Search No CGPA Failure" << endl;
    }
    // Single Result
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kCgpa, firstname, lastname, cgpa1, rscore1);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == " Kevin Todd from AB has a CGPA of 3.99, and a research score of 100\n");
        if (the_stream && the_stream.str() == " Kevin Todd from AB has a CGPA of 3.99, and a research score of 100\n") {
            cout << "Search Single CGPA Success" << endl;
        }
    } catch (...) {
        cout << "Search Single CGPA Failure" << endl;
    }
    // Multiple Results
    try {
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kCgpa, firstname, lastname, cgpa2, rscore2);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert(the_stream && the_stream.str() == " Grayson Ross from NT has a CGPA of 4.33, and a research score of 99\n "
        "Mila Richardson from QC has a CGPA of 4.33, and a research score of 99\n");
        if (the_stream && the_stream.str() == " Grayson Ross from NT has a CGPA of 4.33, and a research score of 99\n "
                "Mila Richardson from QC has a CGPA of 4.33, and a research score of 99\n") {
            cout << "Search Multiple CGPA Success" << endl;
        }
    } catch (...) {
        cout << "Search Multiple CGPA Failure" << endl;
    }
    return true;
}
bool TestDelete(StudentList& test_students){
    string firstname = "Kelvin";
    string firstname1 = "Kevin";
    string firstname2 = "Mary";
    string lastname = "Todd";
    string lastname2 = "White";
    float cgpa = float(3.99);
    int rscore = 100;

    // Empty Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname, lastname);
        assert(test_students.list_length() == list_length);
        if (test_students.list_length() == list_length) {
            cout << "Empty Deletion Success" << endl;
        }

    } catch (...) {
        cout << "Empty Deletion Failure" << endl;
    }

    // Single Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname1, lastname);
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kCgpa, firstname1, lastname, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if (the_stream && the_stream.str() == "") {
            cout << "Single Deletion Success" << endl;
        }

    } catch (...) {
        cout << "Single Deletion Failure" << endl;
    }
    // Multiple Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname2, lastname2);
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kCgpa, firstname2, lastname2, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if ((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length)) {
            cout << "Multiple Deletion Success" << endl;
        }

    } catch (...) {
        cout << "Multiple Deletion Failure" << endl;
    }

    return true;
}

#endif // UNITTEST_HPP
