#ifndef STUDENTLISTS_H
#define STUDENTLISTS_H
#include "student.hpp"

struct Node
{
    Student* a_student_;
    Node* next_;
};

class StudentList
{
private:
    Node* head_;
    Node* tail_;
    int list_length_;

    void DeleteFirst();
        // Pre: Non-empty list
        // Post: Removed list head entry and updated with new head

    void DeleteLast();
        // Pre: Non-empty list
        // Post: Removed list tail entry and updated with new tail

    void InsertOverall(Student* new_student);
        // Pre: List object, complete student object to insert
        // Post: Added new entry to list, placed according to overall sorting criteria

public:
    // Constructors
    StudentList();
    StudentList(const StudentList &old_list);


    // Getters
    Node head() const {return *head_;}
    int list_length() const {return list_length_;}


    // List Manipulation
    void NewStudent(Student* new_student);
        // Pre: Existing list object, complete student object to insert
        // Post: Added new student to list, placed according to called sorting insert function

    void DeleteStudent(int target);
        // Pre: Populated existing list object, target student index (ie 1 <= int <= (list length))
        // Post: Deleted student at specified index

    void PrintList();
        // Pre: Populated existing list object
        // Post: Printed details for each student in list in order
};

#endif // STUDENTLISTS_H
