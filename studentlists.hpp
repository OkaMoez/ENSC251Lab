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
    void DeleteLast();
    void InsertOverall(Student* new_student);

public:
    StudentList();
    StudentList(const StudentList &old_list);

    Node head() const {return *head_;}
    int list_length() const {return list_length_;}

    void NewStudent(Student* new_student);
    void DeleteStudent(int target);
    void PrintList();
};

#endif // STUDENTLISTS_H
