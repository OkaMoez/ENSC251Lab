#ifndef STUDENTLISTS_H
#define STUDENTLISTS_H
#include "functions.hpp"

//ROUGH
class DStudentList
{
private:
    struct DNode
    {
        DomesticStudent a_student_;
        DNode *next_;
    };
    DNode *head_;
    DNode *tail_;
    int list_length_;

public:
    DStudentList();
    void NewStudent(DomesticStudent new_student);
    void InsertOverall(DomesticStudent new_student);
    void InsertFirst(DomesticStudent new_student);
    void InsertLast(DomesticStudent new_student);// kinda redundent #### REVISE ####
    void InsertStudent(int target, DomesticStudent new_student);// #### REVISE ####
    void DeleteFirst();
    void DeleteLast();
    void DeleteStudent(int target);
    void PrintTarget(int target);
    void PrintList();
};

#endif // STUDENTLISTS_H
