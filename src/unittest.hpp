#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <sstream>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "functions.hpp"

void PopulateStudentList (int student_type, StudentList& student_list, string file_path, int debug);
bool TestInsert(StudentList& test_students, Student* student1, Student* student2,
                Student* student3, Student* student4, Student* student5);
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
    // Corner Case Students (First and Last)
    Student* student4 = new DomesticStudent("Aaron", "Alpha", float(4.33), 100, "AB");
    Student* student5 = new DomesticStudent("Zeke", "Zola", 1.00, 1, "YT");

    cout << "Running Unit Tests: " << endl;

    bool passI = TestInsert(test_students, student1, student2, student3, student4, student5);
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
                Student* student3, Student* student4, Student* student5){
    cout << endl << "** Begin 5 Insertion Tests **" << endl;
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
    // Corner Case 3, First Place
    try {
        test_students.NewStudent(student4);
    } catch (...) {
        cout << "Insertion Failure on Student 4" << endl;
        return false;
    }
    // Corner Case 4, Last Place
    try {
        test_students.NewStudent(student5);
    } catch (...) {
        cout << "Insertion Failure on Student 5" << endl;
        return false;
    }
    try {
        assert(test_students.head().a_student_ == student4);
        cout << "Insertion Success on Student 4" << endl;
    } catch (...) {
        cout << "Insertion Failure on Student 4" << endl;
    }
    try {
        assert(test_students.tail().a_student_ == student5);
        cout << "Insertion Success on Student 5" << endl;
    } catch (...) {
        cout << "Insertion Failure on Student 5" << endl;
    }
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

    cout << endl << "** Begin 3 Search Name Tests **" << endl;
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
            cout << "1 - Search No Name Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "1 - Search No Name Failure" << endl;
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
            cout << "2 - Search Single Name Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "2 - Search Single Name Failure" << endl;
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
            cout << "3 - Search Multiple Name Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "3 - Search Multiple Name Failure" << endl;
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

    cout << endl << "** Begin 3 Search CGPA Tests **" << endl;
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
            cout << "1 - Search No CGPA Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "1 - Search No CGPA Failure" << endl;
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
            cout << "2 - Search Single CGPA Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "2 - Search Single CGPA Failure" << endl;
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
            cout << "3 - Search Multiple CGPA Success" << endl;
        }
        else {
            throw 1;
        }
    } catch (...) {
        cout << "3 - Search Multiple CGPA Failure" << endl;
    }
    return true;
}
bool TestDelete(StudentList& test_students){
    string firstname = "Kelvin";
    string firstname1 = "Kevin";
    string firstname2 = "Mary";
    string firstnameA = "Aaron";
    string firstnameZ = "Zeke";
    string lastname = "Todd";
    string lastname2 = "White";
    string lastnameA = "Alpha";
    string lastnameZ = "Zola";
    float cgpa = float(3.99);
    int rscore = 100;

    cout << endl << "** Begin 5 Deletion Tests **" << endl;
    // Empty Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname, lastname);
        assert(test_students.list_length() == list_length);
        if (test_students.list_length() == list_length) {
            cout << "1 - Empty Deletion Success" << endl;
        }
        else {
            throw 1;
        }

    } catch (...) {
        cout << "1 - Empty Deletion Failure" << endl;
    }

    // Single Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname1, lastname);
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstname1, lastname, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if (the_stream && the_stream.str() == "") {
            cout << "2 - Single Deletion Success" << endl;
        }
        else {
            throw 1;
        }

    } catch (...) {
        cout << "2 - Single Deletion Failure" << endl;
    }
    // Multiple Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstname2, lastname2);
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstname2, lastname2, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if ((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length)) {
            cout << "3 - Multiple Deletion Success" << endl;
        }
        else {
            throw 1;
        }

    } catch (...) {
        cout << "3 - Multiple Deletion Failure" << endl;
    }
    // First Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstnameA, lastnameA); // Delete
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstnameA, lastnameA, cgpa, rscore); // Search for Target
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if ((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length)) {
            cout << "4 - First Deletion Success" << endl;
        }
        else {
            throw 1;
        }

    } catch (...) {
        cout << "4 - First Deletion Failure" << endl;
    }
    // Last Deletion
    try {
        int list_length = test_students.list_length();
        SearchAndDestroyLoop(test_students, firstnameZ, lastnameZ);
        std::ostringstream the_stream;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(the_stream.rdbuf());
        SearchLoop(test_students, kFirstName, firstnameZ, lastnameZ, cgpa, rscore);
        std::cout.rdbuf(p_cout_streambuf);
        std::cout << the_stream.str();
        assert((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length));
        if ((the_stream && the_stream.str() == "") && (test_students.list_length() < list_length)) {
            cout << "5 - Last Deletion Success" << endl;
        }
        else {
            throw 1;
        }

    } catch (...) {
        cout << "5 - Last Deletion Failure" << endl;
    }

    return true;
}

#endif // UNITTEST_HPP
