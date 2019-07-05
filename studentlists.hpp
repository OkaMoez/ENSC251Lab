#ifndef STUDENTLISTS_H
#define STUDENTLISTS_H
#include "student.hpp"

struct Node
{
    Student a_student_;
    Node *next_;
};

class StudentList
{
private:
    Node *head_;
    Node *tail_;
    int list_length_;

public:
    StudentList();

    Node head() const {return *head_;}
    int list_length() const {return list_length_;}

    void NewStudent(Student &new_student);
    void InsertOverall(Student &new_student);
    void InsertFirst(Student &new_student);
    void InsertLast(Student &new_student);// kinda redundent #### REVISE ####
    void InsertStudent(int target, Student &new_student);// #### REVISE ####
    void DeleteFirst();
    void DeleteLast();
    void DeleteStudent(int target);
    void PrintTarget(int target);
    void PrintList();
};

#endif // STUDENTLISTS_H
